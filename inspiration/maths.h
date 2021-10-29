#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct quat {
    float x, y, z, w;
} quat;

#define V2 vec2_create 
#define V3 vec3_create
#define V4 vec4_create
#define QUAT quat_create

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

