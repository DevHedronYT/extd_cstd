#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * 4 x 4 matrices
 * Stored in row-order form
 */
typedef struct mat4 {
    float m[16];
} mat4;

typedef struct quat {
    float x, y, z, w;
} quat;

#define V2 vec2_create 
#define V3 vec3_create
#define V4 vec4_create
#define QUAT quat_create

mat4 mat4_create(float a, float b, float c, float d,
                 float e, float f, float g, float h,
                 float i, float j, float k, float l,
                 float m, float n, float o, float p);
mat4 mat4_zero();
mat4 mat4_identity();
mat4 mat4_translation(vec3 v);
mat4 mat4_scale(vec3 v);
mat4 mat4_rotation_x(float theta);
mat4 mat4_rotation_y(float theta);
mat4 mat4_rotation_z(float theta);
mat4 mat4_shear(float theta, vec3 a, vec3 b);
mat4 mat4_multiply_n(int count, ...);
mat4 mat4_multiply(mat4 m1, mat4 m2);
mat4 mat4_inverse(mat4 m);
mat4 mat4_transpose(mat4 m);
mat4 mat4_normal_transform(mat4 m);
mat4 mat4_look_at(vec3 position, vec3 target, vec3 up);
mat4 mat4_from_axes(vec3 x, vec3 y, vec3 z);
void mat4_get_axes(mat4 m, vec3 *x, vec3 *y, vec3 *z);
mat4 mat4_perspective_projection(float fov, float aspect, float near, float far);
mat4 mat4_orthographic_projection(float left, float right, float bottom, float top, float near, float far);
mat4 mat4_from_quat(quat q);
mat4 mat4_box_inertia_tensor(vec3 half_lengths, float mass);
mat4 mat4_sphere_inertia_tensor(float radius, float mass);
mat4 mat4_triangle_transform(vec2 src_p1, vec2 src_p2, vec2 src_p3,
                             vec2 dest_p1, vec2 dest_p2, vec2 dest_p3);
mat4 mat4_box_to_line_transform(vec3 p0, vec3 p1, float sz);
mat4 mat4_interpolate(mat4 m0, mat4 m1, float t);
void mat4_print(mat4 m);

quat quat_create(float x, float y, float z, float w);
float quat_dot(quat v0, quat v1);
quat quat_add(quat v0, quat v1);
quat quat_scale(quat v, float s);
quat quat_subtract(quat v0, quat v1);
quat quat_create_from_axis_angle(vec3 axis, float angle);
quat quat_multiply(quat u, quat v);
quat quat_interpolate(quat u, quat v, float a);
quat quat_slerp(quat u, quat v, float a);
quat quat_normalize(quat q);
quat quat_between_vectors(vec3 u, vec3 v);
void quat_get_axes(quat q, vec3 *x, vec3 *y, vec3 *z);
void quat_get_axis_angle(quat q, vec3 *axis, float *angle);
void quat_print(quat q);


mat4 mat4_create(float a, float b, float c, float d,
                 float e, float f, float g, float h,
                 float i, float j, float k, float l,
                 float m, float n, float o, float p) {
	mat4 mat;
	mat.m[0] = a;
	mat.m[1] = b;
	mat.m[2] = c;
	mat.m[3] = d;
	mat.m[4] = e;
	mat.m[5] = f;
	mat.m[6] = g;
	mat.m[7] = h;
	mat.m[8] = i;
	mat.m[9] = j;
	mat.m[10] = k;
	mat.m[11] = l;
	mat.m[12] = m;
	mat.m[13] = n;
	mat.m[14] = o;
	mat.m[15] = p;
	return mat;
}

mat4 mat4_zero() {
    return mat4_create(
        0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0);
}

mat4 mat4_identity() {
    return mat4_create(
        1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0);
}

mat4 mat4_translation(vec3 v) {
    return mat4_create(
        1.0, 0.0, 0.0, v.x,
        0.0, 1.0, 0.0, v.y,
        0.0, 0.0, 1.0, v.z,
        0.0, 0.0, 0.0, 1.0);
}

mat4 mat4_scale(vec3 v) {
    return mat4_create(
        v.x, 0.0, 0.0, 0.0,
        0.0, v.y, 0.0, 0.0,
        0.0, 0.0, v.z, 0.0,
        0.0, 0.0, 0.0, 1.0);
}

/*
 * https://en.wikipedia.org/wiki/Rotation_matrix
 */
mat4 mat4_rotation_x(float theta) {
    float c = cosf(theta);
    float s = sinf(theta);
    return mat4_create(
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, c, -s, 0.0f,
        0.0f, s, c, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f);
}

mat4 mat4_rotation_y(float theta) {
    float c = cosf(theta);
    float s = sinf(theta);
    return mat4_create(
        c, 0.0f, s, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        -s, 0.0f, c, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f);
}

mat4 mat4_rotation_z(float theta) {
    float c = cosf(theta);
    float s = sinf(theta);
    return mat4_create(
        c, -s, 0.0f, 0.0f,
        s, c, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f);
}

mat4 mat4_shear(float theta, vec3 a, vec3 b) {
    float t = tanf(theta);
    return mat4_create(
        a.x * b.x * t + 1.0f, a.x * b.y * t, a.x * b.z * t, 0.0f,
        a.y * b.x * t, a.y * b.y * t + 1.0f, a.y * b.z * t, 0.0f,
        a.z * b.x * t, a.z * b.y * t, a.z * b.z * t + 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f);
}

void mat4_print(mat4 m) {
    float *a = m.m;
    printf("[%f, %f, %f, %f]\n", a[0], a[1], a[2], a[3]);
    printf("[%f, %f, %f, %f]\n", a[4], a[5], a[6], a[7]);
    printf("[%f, %f, %f, %f]\n", a[8], a[9], a[10], a[11]);
    printf("[%f, %f, %f, %f]\n", a[12], a[13], a[14], a[15]);
}

mat4 mat4_multiply_n(int count, ...) {
    va_list args;
    va_start(args, count);
    mat4 result = mat4_identity();
    for (int i = 0; i < count; i++) {
        result = mat4_multiply(result, va_arg(args, mat4));
    }
    va_end(args);
    return result;
}

mat4 mat4_multiply(mat4 m1, mat4 m2) {
    float *a = m1.m;
    float *b = m2.m;

    float c0 = a[0] * b[0] + a[1] * b[4] + a[2] * b[8] + a[3] * b[12];
    float c1 = a[0] * b[1] + a[1] * b[5] + a[2] * b[9] + a[3] * b[13];
    float c2 = a[0] * b[2] + a[1] * b[6] + a[2] * b[10] + a[3] * b[14];
    float c3 = a[0] * b[3] + a[1] * b[7] + a[2] * b[11] + a[3] * b[15];

    float c4 = a[4] * b[0] + a[5] * b[4] + a[6] * b[8] + a[7] * b[12];
    float c5 = a[4] * b[1] + a[5] * b[5] + a[6] * b[9] + a[7] * b[13];
    float c6 = a[4] * b[2] + a[5] * b[6] + a[6] * b[10] + a[7] * b[14];
    float c7 = a[4] * b[3] + a[5] * b[7] + a[6] * b[11] + a[7] * b[15];

    float c8 = a[8] * b[0] + a[9] * b[4] + a[10] * b[8] + a[11] * b[12];
    float c9 = a[8] * b[1] + a[9] * b[5] + a[10] * b[9] + a[11] * b[13];
    float c10 = a[8] * b[2] + a[9] * b[6] + a[10] * b[10] + a[11] * b[14];
    float c11 = a[8] * b[3] + a[9] * b[7] + a[10] * b[11] + a[11] * b[15];

    float c12 = a[12] * b[0] + a[13] * b[4] + a[14] * b[8] + a[15] * b[12];
    float c13 = a[12] * b[1] + a[13] * b[5] + a[14] * b[9] + a[15] * b[13];
    float c14 = a[12] * b[2] + a[13] * b[6] + a[14] * b[10] + a[15] * b[14];
    float c15 = a[12] * b[3] + a[13] * b[7] + a[14] * b[11] + a[15] * b[15];

    return mat4_create(
        c0, c1, c2, c3,
        c4, c5, c6, c7,
        c8, c9, c10, c11,
        c12, c13, c14, c15);
}

mat4 mat4_transpose(mat4 m) {
    float *a = m.m;

    return mat4_create(
        a[0], a[4], a[8], a[12],
        a[1], a[5], a[9], a[13],
        a[2], a[6], a[10], a[14],
        a[3], a[7], a[11], a[15]);
}

mat4 mat4_normal_transform(mat4 m) {
    return mat4_transpose(mat4_inverse(m));
}

/*
 * http://www.cg.info.hiroshima-cu.ac.jp/~miyazaki/knowledge/teche23.html
 */
mat4 mat4_inverse(mat4 m) {
    float *a = m.m;

    float det =
        a[0] * a[5] * a[10] * a[15] +
        a[0] * a[6] * a[11] * a[13] +
        a[0] * a[7] * a[9] * a[14] +

        a[1] * a[4] * a[11] * a[14] +
        a[1] * a[6] * a[8] * a[15] +
        a[1] * a[7] * a[10] * a[12] +

        a[2] * a[4] * a[9] * a[15] +
        a[2] * a[5] * a[11] * a[12] +
        a[2] * a[7] * a[8] * a[13] +

        a[3] * a[4] * a[10] * a[13] +
        a[3] * a[5] * a[8] * a[14] +
        a[3] * a[6] * a[9] * a[12] -

        a[0] * a[5] * a[11] * a[14] -
        a[0] * a[6] * a[9] * a[15] -
        a[0] * a[7] * a[10] * a[13] -

        a[1] * a[4] * a[10] * a[15] -
        a[1] * a[6] * a[11] * a[12] -
        a[1] * a[7] * a[8] * a[14] -

        a[2] * a[4] * a[11] * a[13] -
        a[2] * a[5] * a[8] * a[15] -
        a[2] * a[7] * a[9] * a[12] -

        a[3] * a[4] * a[9] * a[14] -
        a[3] * a[5] * a[10] * a[12] -
        a[3] * a[6] * a[8] * a[13];

    if (det == 0.0) {
        return mat4_identity();
    }

    float a0 = a[5] * a[10] * a[15] + a[6] * a[11] * a[13] + a[7] * a[9] * a[14] - a[5] * a[11] * a[14] - a[6] * a[9] * a[15] - a[7] * a[10] * a[13];

    float a1 = a[1] * a[11] * a[14] + a[2] * a[9] * a[15] + a[3] * a[10] * a[13] - a[1] * a[10] * a[15] - a[2] * a[11] * a[13] - a[3] * a[9] * a[14];

    float a2 = a[1] * a[6] * a[15] + a[2] * a[7] * a[13] + a[3] * a[5] * a[14] - a[1] * a[7] * a[14] - a[2] * a[5] * a[15] - a[3] * a[6] * a[13];

    float a3 = a[1] * a[7] * a[10] + a[2] * a[5] * a[11] + a[3] * a[6] * a[9] - a[1] * a[6] * a[11] - a[2] * a[7] * a[9] - a[3] * a[5] * a[10];

    float a4 = a[4] * a[11] * a[14] + a[6] * a[8] * a[15] + a[7] * a[10] * a[12] - a[4] * a[10] * a[15] - a[6] * a[11] * a[12] - a[7] * a[8] * a[14];

    float a5 = a[0] * a[10] * a[15] + a[2] * a[11] * a[12] + a[3] * a[8] * a[14] - a[0] * a[11] * a[14] - a[2] * a[8] * a[15] - a[3] * a[10] * a[12];

    float a6 = a[0] * a[7] * a[14] + a[2] * a[4] * a[15] + a[3] * a[6] * a[12] - a[0] * a[6] * a[15] - a[2] * a[7] * a[12] - a[3] * a[4] * a[14];

    float a7 = a[0] * a[6] * a[11] + a[2] * a[7] * a[8] + a[3] * a[4] * a[10] - a[0] * a[7] * a[10] - a[2] * a[4] * a[11] - a[3] * a[6] * a[8];

    float a8 = a[4] * a[9] * a[15] + a[5] * a[11] * a[12] + a[7] * a[8] * a[13] - a[4] * a[11] * a[13] - a[5] * a[8] * a[15] - a[7] * a[9] * a[12];

    float a9 = a[0] * a[11] * a[13] + a[1] * a[8] * a[15] + a[3] * a[9] * a[12] - a[0] * a[9] * a[15] - a[1] * a[11] * a[12] - a[3] * a[8] * a[13];

    float a10 = a[0] * a[5] * a[15] + a[1] * a[7] * a[12] + a[3] * a[4] * a[13] - a[0] * a[7] * a[13] - a[1] * a[4] * a[15] - a[3] * a[5] * a[12];

    float a11 = a[0] * a[7] * a[9] + a[1] * a[4] * a[11] + a[3] * a[5] * a[8] - a[0] * a[5] * a[11] - a[1] * a[7] * a[8] - a[3] * a[4] * a[9];

    float a12 = a[4] * a[10] * a[13] + a[5] * a[8] * a[14] + a[6] * a[9] * a[12] - a[4] * a[9] * a[14] - a[5] * a[10] * a[12] - a[6] * a[8] * a[13];

    float a13 = a[0] * a[9] * a[14] + a[1] * a[10] * a[12] + a[2] * a[8] * a[13] - a[0] * a[10] * a[13] - a[1] * a[8] * a[14] - a[2] * a[9] * a[12];

    float a14 = a[0] * a[6] * a[13] + a[1] * a[4] * a[14] + a[2] * a[5] * a[12] - a[0] * a[5] * a[14] - a[1] * a[6] * a[12] - a[2] * a[4] * a[13];

    float a15 = a[0] * a[5] * a[10] + a[1] * a[6] * a[8] + a[2] * a[4] * a[9] - a[0] * a[6] * a[9] - a[1] * a[4] * a[10] - a[2] * a[5] * a[8];

    return mat4_create(
        a0 / det, a1 / det, a2 / det, a3 / det,
        a4 / det, a5 / det, a6 / det, a7 / det,
        a8 / det, a9 / det, a10 / det, a11 / det,
        a12 / det, a13 / det, a14 / det, a15 / det);
}

/*
 * http://www.cs.virginia.edu/~gfx/Courses/1999/intro.fall99.html/lookat.html
 */
mat4 mat4_look_at(vec3 position, vec3 target, vec3 up) {
    vec3 up_p = vec3_normalize(up);
    vec3 f = vec3_normalize(vec3_subtract(target, position));
    vec3 s = vec3_normalize(vec3_cross(f, up_p));
    vec3 u = vec3_normalize(vec3_cross(s, f));

    mat4 M = mat4_create(
        s.x, s.y, s.z, 0.0,
        u.x, u.y, u.z, 0.0,
        -f.x, -f.y, -f.z, 0.0,
        0.0, 0.0, 0.0, 1.0);
    mat4 T = mat4_translation(vec3_scale(position, -1.0));

    return mat4_multiply(M, T);
}

mat4 mat4_from_axes(vec3 x, vec3 y, vec3 z) {
    return mat4_create(
        x.x, x.y, x.z, 0.0f,
        y.x, y.y, y.z, 0.0f,
        z.x, z.y, z.z, 0.0f,
        0.0, 0.0, 0.0, 1.0f);
}

void mat4_get_axes(mat4 m, vec3 *x, vec3 *y, vec3 *z) {
    x->x = m.m[0];
    x->y = m.m[1];
    x->z = m.m[2];

    y->x = m.m[4];
    y->y = m.m[5];
    y->z = m.m[6];

    z->x = m.m[8];
    z->y = m.m[9];
    z->z = m.m[10];
}

/*
 * http://www.cs.virginia.edu/~gfx/Courses/2000/intro.spring00.html/lectures/lecture09/sld017.htm
 */
mat4 mat4_perspective_projection(float fov, float aspect, float near, float far) {
    float f = 1.0f / tanf(fov * DEGREES_PER_RADIAN / 2.0f);
    float denominator = near - far;

    float a = f / aspect;
    float b = f;
    float c = (far + near) / denominator;
    float d = (2.0f * far * near) / denominator;

    return mat4_create(
        a, 0.0f, 0.0f, 0.0f,
        0.0f, b, 0.0f, 0.0f,
        0.0f, 0.0f, c, d,
        0.0f, 0.0f, -1.0f, 0.0f);
}

/*
 * https://en.wikipedia.org/wiki/Orthographic_projection
 */
mat4 mat4_orthographic_projection(float left, float right, float bottom, float top,
        float near, float far) {
    float a = 2.0f / (right - left);
    float b = 2.0f / (top - bottom);
    float c = -2.0f / (far - near);
    float d = -(right + left) / (right - left);
    float e = -(top + bottom) / (top - bottom);
    float f = -(far + near) / (far - near);

    return mat4_create(
        a, 0.0f, 0.0f, d,
        0.0f, b, 0.0f, e,
        0.0f, 0.0f, c, f,
        0.0f, 0.0f, 0.0f, 1.0f);
}

mat4 mat4_from_quat(quat q) {
    float x = q.x;
    float y = q.y;
    float z = q.z;
    float w = q.w;

    return mat4_create(
        1.0f - 2.0f * y * y - 2.0f * z * z, 2.0f * x * y - 2.0f * w * z, 2.0f * x * z + 2.0f * w * y,
        0.0f,
        2.0f * x * y + 2.0f * w * z, 1.0f - 2.0f * x * x - 2.0f * z * z, 2.0f * y * z - 2.0f * w * x,
        0.0f,
        2.0f * x * z - 2.0f * w * y, 2.0f * y * z + 2.0f * w * x, 1.0f - 2.0f * x * x - 2.0f * y * y,
        0.0f,
        0.0f, 0.0f, 0.0f, 1.0f);
}

mat4 mat4_box_inertia_tensor(vec3 half_lengths, float mass) {
    return mat4_create(
        (1.0f / 12.0f) * mass * (half_lengths.x + half_lengths.y), 0.0f, 0.0f, 0.0f,
        0.0f, (1.0f / 12.0f) * mass * (half_lengths.y + half_lengths.z), 0.0f, 0.0f,
        0.0f, 0.0f, (1.0f / 12.0f) * mass * (half_lengths.z + half_lengths.x), 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f);
}

mat4 mat4_sphere_inertia_tensor(float radius, float mass) {
    return mat4_create(
        (2.0f / 5.0f) * mass * radius * radius, 0.0f, 0.0f, 0.0f,
        0.0f, (2.0f / 5.0f) * mass * radius * radius, 0.0f, 0.0f,
        0.0f, 0.0f, (2.0f / 5.0f) * mass * radius * radius, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f);
}

mat4 mat4_triangle_transform(vec2 src_p1, vec2 src_p2, vec2 src_p3,
                             vec2 dest_p1, vec2 dest_p2, vec2 dest_p3) {
    float x11 = src_p1.x;
    float x12 = src_p1.y;
    float x21 = src_p2.x;
    float x22 = src_p2.y;
    float x31 = src_p3.x;
    float x32 = src_p3.y;
    float y11 = dest_p1.x;
    float y12 = dest_p1.y;
    float y21 = dest_p2.x;
    float y22 = dest_p2.y;
    float y31 = dest_p3.x;
    float y32 = dest_p3.y;

    float a1 = ((y11 - y21) * (x12 - x32) - (y11 - y31) * (x12 - x22)) /
               ((x11 - x21) * (x12 - x32) - (x11 - x31) * (x12 - x22));
    float a2 = ((y11 - y21) * (x11 - x31) - (y11 - y31) * (x11 - x21)) /
               ((x12 - x22) * (x11 - x31) - (x12 - x32) * (x11 - x21));
    float a3 = y11 - a1 * x11 - a2 * x12;
    float a4 = ((y12 - y22) * (x12 - x32) - (y12 - y32) * (x12 - x22)) /
               ((x11 - x21) * (x12 - x32) - (x11 - x31) * (x12 - x22));
    float a5 = ((y12 - y22) * (x11 - x31) - (y12 - y32) * (x11 - x21)) /
               ((x12 - x22) * (x11 - x31) - (x12 - x32) * (x11 - x21));
    float a6 = y12 - a4 * x11 - a5 * x12;

    return mat4_create(a1, a2, a3, 0.0f,
                       a4, a5, a6, 0.0f,
                       0.0f, 0.0f, 1.0f, 0.0f,
                       0.0f, 0.0f, 0.0f, 1.0f);
}

mat4 mat4_box_to_line_transform(vec3 p0, vec3 p1, float sz) {
    float dist = vec3_distance(p0, p1); 
    vec3 v0 = V3(1.0f, 0.0f, 0.0f);
    vec3 v1 = vec3_normalize(vec3_subtract(p1, p0));
    quat q = quat_between_vectors(v0, v1);

    return mat4_multiply_n(4,
            mat4_translation(p0),
            mat4_from_quat(q),
            mat4_scale(V3(0.5f * dist, 0.5f * sz, 0.5f * sz)),
            mat4_translation(V3(1.0f, 0.0f, 0.0f)));
}

mat4 mat4_interpolate(mat4 m0, mat4 m1, float t) {
    mat4 m;
    for (int i = 0; i < 16; i++) {
        m.m[i] = m0.m[i] + (m1.m[i] - m0.m[i]) * t;
    }
    return m;
}

quat quat_create(float x, float y, float z, float w) {
	quat q;
	q.x = x;
	q.y = y;
	q.z = z;
	q.w = w;
	return q;
}

quat quat_create_from_axis_angle(vec3 axis, float angle) {
    axis = vec3_normalize(axis);
    float temp = sinf(angle / 2.0f);
    float x = temp * axis.x;
    float y = temp * axis.y;
    float z = temp * axis.z;
    float w = cosf(angle / 2.0f);
    return quat_create(x, y, z, w);
}

quat quat_multiply(quat u, quat v) {
    float x = v.w * u.x + v.x * u.w - v.y * u.z + v.z * u.y;
    float y = v.w * u.y + v.x * u.z + v.y * u.w - v.z * u.x;
    float z = v.w * u.z - v.x * u.y + v.y * u.x + v.z * u.w;
    float w = v.w * u.w - v.x * u.x - v.y * u.y - v.z * u.z;
    return quat_normalize(quat_create(x, y, z, w));
}

quat quat_normalize(quat q) {
    float mag = sqrtf(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);

    if (mag == 0.0f) {
        return q;
    }

    return quat_create(q.x / mag, q.y / mag, q.z / mag, q.w / mag);
}

quat quat_interpolate(quat u, quat v, float a) {
    quat r;
    u = quat_normalize(u);
    v = quat_normalize(v);

    r.x = u.x + (v.x - u.x) * a;
    r.y = u.y + (v.y - u.y) * a;
    r.z = u.z + (v.z - u.z) * a;
    r.w = u.w + (v.w - u.w) * a;

    return quat_normalize(r);
}

quat quat_subtract(quat q1, quat q2) {
    return QUAT(q1.x - q2.x, q1.y - q2.y, q1.z - q2.z, q1.w - q2.w);
}

quat quat_add(quat q1, quat q2) {
    return QUAT(q1.x + q2.x, q1.y + q2.y, q1.z + q2.z, q1.w + q2.w);
}

float quat_dot(quat v0, quat v1) {
    return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z + v0.w * v1.w;
}

quat quat_scale(quat v, float s) {
    return QUAT(v.x * s, v.y * s, v.z * s, v.w * s);
}

quat quat_slerp(quat v0, quat v1, float a) {
    v0 = quat_normalize(v0);
    v1 = quat_normalize(v1);

    float dot = quat_dot(v0, v1);
    if (fabs(dot) > 0.95f) {
        return quat_add(v0, quat_scale(quat_subtract(v1, v0), a));
    }

    if (dot < 0.0f) {
        v1 = quat_scale(v1, -1.0f);
        dot = -dot;
    }

    dot = fminf(fmaxf(-1.0f, dot), 1.0f);
    float theta_0 = acosf(dot);
    float theta = theta_0 * a;

    quat v2 = quat_subtract(v1, quat_scale(v0, a));
    v2 = quat_normalize(v2);

    return quat_add(quat_scale(v0, cosf(theta)), quat_scale(v2, sinf(theta)));
}

quat quat_between_vectors(vec3 u, vec3 v) {
    float k_cos_theta = vec3_dot(u, v);
    float k = sqrtf(vec3_length_squared(u) * vec3_length_squared(v));

    if (k_cos_theta / k == -1.0f) {
        vec3 orth = vec3_normalize(vec3_orthogonal(u));
        return QUAT(orth.x, orth.y, orth.z, 0.0f);
    }

    vec3 cross = vec3_cross(u, v);
    return quat_normalize(QUAT(cross.x, cross.y, cross.z, k_cos_theta + k));
}

void quat_get_axes(quat q, vec3 *x, vec3 *y, vec3 *z) {
    mat4 m = mat4_from_quat(q);

    x->x = m.m[0];
    y->x = m.m[1];
    z->x = m.m[2];

    x->y = m.m[4];
    y->y = m.m[5];
    z->y = m.m[6];

    x->z = m.m[8];
    y->z = m.m[9];
    z->z = m.m[10];
}

void quat_get_axis_angle(quat q, vec3 *axis, float *angle) {
    *angle = 2.0f * acosf(q.w);
    axis->x = q.x / sqrtf(1.0f - q.w*q.w);
    axis->y = q.y / sqrtf(1.0f - q.w*q.w);
    axis->z = q.z / sqrtf(1.0f - q.w*q.w);
}

void quat_print(quat q) {
    printf("<%f, %f, %f, %f>\n", q.x, q.y, q.z, q.w);
}

