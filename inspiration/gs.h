/*
 
GS_MATH:
Gunslinger includes utilities for common graphics/game related math structures.
These aren't required to be used, however they are used internally for certain 
function calls in various APIs. Where possible, I've tried to add as much 
redundancy as possible to the APIs so that these structures are not required 
if you prefer.

* common utils:
    - interpolation

* Vectors:
    - gs_vec2: float[2]
    - gs_vec3: float[3]
    - gs_vec4: float[4]
        * vector ops: 
            - dot product
            - normalize
            - add/subtract (component wise)
            - multiply
            - cross product
            - length
        
*Quaternions:
    - gs_quat: float[4]
        * quaternion ops:
            - add/subtract/multiply
            - inverse
            - conjugate
            - angle/axis | axis/angle
            - to euler | from euler
            - to mat4

*Mat4x4: 
    - gs_mat4: float[16]
        * mat4 ops:
            - add/subtract/multiply
            - transpose
            - inverse
            - homogenous transformations:
                - rotation 
                - scale
                - translate
            - view: 
                - lookat
            - projection: 
                - orthographic
                - perspective

*VQS:
    - gs_vqs:  gs_vec3, gs_quat, gs_vec3

(SPECIAL NOTE): 

`gs_vqs` is a transform structure that's commonly used in games/physics 
sims, especially with complex child/parent hierarchies. It stands for
`Vector-Quaternion-Scalar` to denote its internal components. Typically
this encodes position, rotation (in quaternion), and a uniform scale
for transformation. Gunslinger uses non-uniform scale in the form of a
gs_vec3. 

    gs_vqs xform = {0};
    xform.position = gs_v3(...);
    xform.rotation = gs_quat(...);
    xform.scale = gs_v3(...);

This structure can then be converted into a final form float[16] mat4x4
for any typical homogenous graphics transformations:

    gs_mat4 model = gs_vqs_to_mat4(&xform);

The real power in VQS transforms is the ability to easily encode parent/child
hierarchies. This is done using the two functions `gs_vqs_absolute_transform` 
and `gs_vqs_relative_transform`: 

    gs_vqs parent = ...;
    gs_vqs child =  ...; {

    // Get relative transform with respect to parent
    gs_vqs relative = gs_vqs_relative_transform(&child, &parent);   
    // Get absolute transform with respect to local
    gs_vqs absolute = gs_vqs_absolute_transform(&local, &parent);   

*/

/*========================
// GS_MATH
========================*/

/** @defgroup gs_math Math
 *  Gunslinger Math
 *  @{
 */

// Defines
#define GS_EPSILON  (1e-6)
#define GS_PI       3.1415926535897932
#define GS_TAU      2.0 * GS_PI

// Useful Utility
#define gs_v2(...)  gs_vec2_ctor(__VA_ARGS__)
#define gs_v3(...)  gs_vec3_ctor(__VA_ARGS__)
#define gs_v4(...)  gs_vec4_ctor(__VA_ARGS__)
#define gs_quat(...) gs_quat_ctor(__VA_ARGS__)

#define gs_v2s(__S)  gs_vec2_ctor((__S), (__S))
#define gs_v3s(__S)  gs_vec3_ctor((__S), (__S), (__S))
#define gs_v4s(__S)  gs_vec4_ctor((__S), (__S), (__S), (__S))

#define gs_v4_xy_v(__X, __Y, __V) gs_vec4_ctor((__X), (__Y), (__V).x, (__V).y)
#define gs_v4_xyz_s(__XYZ, __S) gs_vec4_ctor((__XYZ).x, (__XYZ).y, (__XYZ).z, (__S))

#define GS_XAXIS    gs_v3(1.f, 0.f, 0.f)
#define GS_YAXIS    gs_v3(0.f, 1.f, 0.f)
#define GS_ZAXIS    gs_v3(0.f, 0.f, 1.f)

/*================================================================================
// Useful Common Math Functions
================================================================================*/
// Interpolation
// Source: https://codeplea.com/simple-interpolation
// Easings from: https://github.com/raysan5/raylib/blob/ea0f6c7a26f3a61f3be542aa8f066ce033766a9f/examples/others/easings.h
//
/*================================================================================
// Mat3x3
================================================================================*/

/*
    Matrices are stored in linear, contiguous memory and assume a column-major ordering.
*/

typedef struct gs_mat3 {
    f32 m[9];
} gs_mat3;

gs_inline gs_mat3 gs_mat3_diag(float val)
{
    gs_mat3 m = gs_default_val();
    m.m[0 + 0 * 3] = val;
    m.m[1 + 1 * 3] = val;
    m.m[2 + 2 * 3] = val;
    return m;
}

#define gs_mat3_identity()\
    gs_mat3_diag(1.f)

gs_inline gs_mat3 
gs_mat3_mul(gs_mat3 m0, gs_mat3 m1)
{
    gs_mat3 m = gs_default_val();

    for (u32 y = 0; y < 3; ++y)
    {
        for (u32 x = 0; x < 3; ++x)
        {
            f32 sum = 0.0f;
            for (u32 e = 0; e < 3; ++e)
            {
                sum += m0.m[x + e * 3] * m1.m[e + y * 3];
            }
            m.m[x + y * 3] = sum;
        }
    }

    return m;
}

gs_inline gs_vec3 
gs_mat3_mul_vec3(gs_mat3 m, gs_vec3 v)
{
    return gs_vec3_ctor(
        m.m[0] * v.x + m.m[1] * v.y + m.m[2] * v.z,
        m.m[3] * v.x + m.m[4] * v.y + m.m[5] * v.z,
        m.m[6] * v.x + m.m[7] * v.y + m.m[8] * v.z
    );
}

gs_inline gs_mat3 
gs_mat3_rotate(float radians, float x, float y, float z)
{
    gs_mat3 m = gs_default_val();
    float s = sinf(radians), c = cosf(radians), c1 = 1.f - c;
    float xy = x * y;
    float yz = y * z;
    float zx = z * x;
    float xs = x * s;
    float ys = y * s;
    float zs = z * s;
    m.m[0] = c1 * x * x + c; m.m[1] = c1 * xy - zs;   m.m[2] = c1 * zx + ys; 
    m.m[3] = c1 * xy + zs;   m.m[4] = c1 * y * y + c; m.m[5] = c1 * yz - xs;
    m.m[6] = c1 * zx - ys;   m.m[7] = c1 * yz + xs;   m.m[8] = c1 * z * z + c;
    return m;
}

gs_inline gs_mat3
gs_mat3_rotatev(float radians, gs_vec3 axis)
{
    return gs_mat3_rotate(radians, axis.x, axis.y, axis.z);
}

// Turn quaternion into mat3
gs_inline gs_mat3 
gs_mat3_rotateq(gs_vec4 q)
{
    gs_mat3 m = gs_default_val();
    float x2 = q.x * q.x, y2 = q.y * q.y, z2 = q.z * q.z, w2 = q.w * q.w;
    float xz = q.x  *q.z, xy = q.x * q.y, yz = q.y * q.z, wz = q.w * q.z, wy = q.w * q.y, wx = q.w * q.x;
    m.m[0] = 1 - 2 * (y2 + z2); m.m[1] = 2 * (xy + wz);     m.m[2] = 2 * (xz - wy);
    m.m[3] = 2 * (xy - wz);     m.m[4] = 1 - 2 * (x2 + z2); m.m[5] = 2 * (yz + wx);
    m.m[6] = 2 * (xz + wy);     m.m[7] = 2 * (yz - wx);     m.m[8] = 1 - 2 * (x2 + y2);
    return m;
}

gs_inline gs_mat3 
gs_mat3_rsq(gs_vec4 q, gs_vec3 s)
{
    gs_mat3 mr = gs_mat3_rotateq(q);
    gs_mat3 ms = gs_mat3_scale(s.x, s.y, s.z);
    return gs_mat3_mul(mr, ms);
}

gs_inline gs_mat3
gs_mat3_inverse(gs_mat3 m)
{
    gs_mat3 r = gs_default_val();

    double det = (double)(m.m[0 * 3 + 0] * (m.m[1 * 3 + 1] * m.m[2 * 3 + 2] - m.m[2 * 3 + 1] * m.m[1 * 3 + 2]) -
                m.m[0 * 3 + 1] * (m.m[1 * 3 + 0] * m.m[2 * 3 + 2] - m.m[1 * 3 + 2] * m.m[2 * 3 + 0]) +
                m.m[0 * 3 + 2] * (m.m[1 * 3 + 0] * m.m[2 * 3 + 1] - m.m[1 * 3 + 1] * m.m[2 * 3 + 0]));

    double inv_det = det ? 1.0 / det : 0.0;

    r.m[0 * 3 + 0] = (m.m[1 * 3 + 1] * m.m[2 * 3 + 2] - m.m[2 * 3 + 1] * m.m[1 * 3 + 2]) * inv_det;
    r.m[0 * 3 + 1] = (m.m[0 * 3 + 2] * m.m[2 * 3 + 1] - m.m[0 * 3 + 1] * m.m[2 * 3 + 2]) * inv_det;
    r.m[0 * 3 + 2] = (m.m[0 * 3 + 1] * m.m[1 * 3 + 2] - m.m[0 * 3 + 2] * m.m[1 * 3 + 1]) * inv_det;
    r.m[1 * 3 + 0] = (m.m[1 * 3 + 2] * m.m[2 * 3 + 0] - m.m[1 * 3 + 0] * m.m[2 * 3 + 2]) * inv_det;
    r.m[1 * 3 + 1] = (m.m[0 * 3 + 0] * m.m[2 * 3 + 2] - m.m[0 * 3 + 2] * m.m[2 * 3 + 0]) * inv_det;
    r.m[1 * 3 + 2] = (m.m[1 * 3 + 0] * m.m[0 * 3 + 2] - m.m[0 * 3 + 0] * m.m[1 * 3 + 2]) * inv_det;
    r.m[2 * 3 + 0] = (m.m[1 * 3 + 0] * m.m[2 * 3 + 1] - m.m[2 * 3 + 0] * m.m[1 * 3 + 1]) * inv_det;
    r.m[2 * 3 + 1] = (m.m[2 * 3 + 0] * m.m[0 * 3 + 1] - m.m[0 * 3 + 0] * m.m[2 * 3 + 1]) * inv_det;
    r.m[2 * 3 + 2] = (m.m[0 * 3 + 0] * m.m[1 * 3 + 1] - m.m[1 * 3 + 0] * m.m[0 * 3 + 1]) * inv_det;

    return r;
}

/*================================================================================
// Mat4x4
================================================================================*/

/*
    Matrices are stored in linear, contiguous memory and assume a column-major ordering.
*/

typedef struct gs_mat4
{
    f32 elements[16];
} gs_mat4;

gs_inline
gs_mat4 gs_mat4_transpose(gs_mat4 m)
{
    gs_mat4 t = gs_mat4_identity();

    // First row
    t.elements[0 * 4 + 0] = m.elements[0 * 4 + 0];
    t.elements[1 * 4 + 0] = m.elements[0 * 4 + 1];
    t.elements[2 * 4 + 0] = m.elements[0 * 4 + 2];
    t.elements[3 * 4 + 0] = m.elements[0 * 4 + 3];

    // Second row
    t.elements[0 * 4 + 1] = m.elements[1 * 4 + 0];
    t.elements[1 * 4 + 1] = m.elements[1 * 4 + 1];
    t.elements[2 * 4 + 1] = m.elements[1 * 4 + 2];
    t.elements[3 * 4 + 1] = m.elements[1 * 4 + 3];

    // Third row
    t.elements[0 * 4 + 2] = m.elements[2 * 4 + 0];
    t.elements[1 * 4 + 2] = m.elements[2 * 4 + 1];
    t.elements[2 * 4 + 2] = m.elements[2 * 4 + 2];
    t.elements[3 * 4 + 2] = m.elements[2 * 4 + 3];

    // Fourth row
    t.elements[0 * 4 + 3] = m.elements[3 * 4 + 0];
    t.elements[1 * 4 + 3] = m.elements[3 * 4 + 1];
    t.elements[2 * 4 + 3] = m.elements[3 * 4 + 2];
    t.elements[3 * 4 + 3] = m.elements[3 * 4 + 3];

    return t;
}

gs_inline
gs_mat4 gs_mat4_inverse(gs_mat4 m)
{
    gs_mat4 res = gs_mat4_identity();

    f32 temp[16];

    temp[0] = m.elements[5] * m.elements[10] * m.elements[15] -
        m.elements[5] * m.elements[11] * m.elements[14] -
        m.elements[9] * m.elements[6] * m.elements[15] +
        m.elements[9] * m.elements[7] * m.elements[14] +
        m.elements[13] * m.elements[6] * m.elements[11] -
        m.elements[13] * m.elements[7] * m.elements[10];

    temp[4] = -m.elements[4] * m.elements[10] * m.elements[15] +
        m.elements[4] * m.elements[11] * m.elements[14] +
        m.elements[8] * m.elements[6] * m.elements[15] -
        m.elements[8] * m.elements[7] * m.elements[14] -
        m.elements[12] * m.elements[6] * m.elements[11] +
        m.elements[12] * m.elements[7] * m.elements[10];

    temp[8] = m.elements[4] * m.elements[9] * m.elements[15] -
        m.elements[4] * m.elements[11] * m.elements[13] -
        m.elements[8] * m.elements[5] * m.elements[15] +
        m.elements[8] * m.elements[7] * m.elements[13] +
        m.elements[12] * m.elements[5] * m.elements[11] -
        m.elements[12] * m.elements[7] * m.elements[9];

    temp[12] = -m.elements[4] * m.elements[9] * m.elements[14] +
        m.elements[4] * m.elements[10] * m.elements[13] +
        m.elements[8] * m.elements[5] * m.elements[14] -
        m.elements[8] * m.elements[6] * m.elements[13] -
        m.elements[12] * m.elements[5] * m.elements[10] +
        m.elements[12] * m.elements[6] * m.elements[9];

    temp[1] = -m.elements[1] * m.elements[10] * m.elements[15] +
        m.elements[1] * m.elements[11] * m.elements[14] +
        m.elements[9] * m.elements[2] * m.elements[15] -
        m.elements[9] * m.elements[3] * m.elements[14] -
        m.elements[13] * m.elements[2] * m.elements[11] +
        m.elements[13] * m.elements[3] * m.elements[10];

    temp[5] = m.elements[0] * m.elements[10] * m.elements[15] -
        m.elements[0] * m.elements[11] * m.elements[14] -
        m.elements[8] * m.elements[2] * m.elements[15] +
        m.elements[8] * m.elements[3] * m.elements[14] +
        m.elements[12] * m.elements[2] * m.elements[11] -
        m.elements[12] * m.elements[3] * m.elements[10];

    temp[9] = -m.elements[0] * m.elements[9] * m.elements[15] +
        m.elements[0] * m.elements[11] * m.elements[13] +
        m.elements[8] * m.elements[1] * m.elements[15] -
        m.elements[8] * m.elements[3] * m.elements[13] -
        m.elements[12] * m.elements[1] * m.elements[11] +
        m.elements[12] * m.elements[3] * m.elements[9];

    temp[13] = m.elements[0] * m.elements[9] * m.elements[14] -
        m.elements[0] * m.elements[10] * m.elements[13] -
        m.elements[8] * m.elements[1] * m.elements[14] +
        m.elements[8] * m.elements[2] * m.elements[13] +
        m.elements[12] * m.elements[1] * m.elements[10] -
        m.elements[12] * m.elements[2] * m.elements[9];

    temp[2] = m.elements[1] * m.elements[6] * m.elements[15] -
        m.elements[1] * m.elements[7] * m.elements[14] -
        m.elements[5] * m.elements[2] * m.elements[15] +
        m.elements[5] * m.elements[3] * m.elements[14] +
        m.elements[13] * m.elements[2] * m.elements[7] -
        m.elements[13] * m.elements[3] * m.elements[6];

    temp[6] = -m.elements[0] * m.elements[6] * m.elements[15] +
        m.elements[0] * m.elements[7] * m.elements[14] +
        m.elements[4] * m.elements[2] * m.elements[15] -
        m.elements[4] * m.elements[3] * m.elements[14] -
        m.elements[12] * m.elements[2] * m.elements[7] +
        m.elements[12] * m.elements[3] * m.elements[6];

    temp[10] = m.elements[0] * m.elements[5] * m.elements[15] -
        m.elements[0] * m.elements[7] * m.elements[13] -
        m.elements[4] * m.elements[1] * m.elements[15] +
        m.elements[4] * m.elements[3] * m.elements[13] +
        m.elements[12] * m.elements[1] * m.elements[7] -
        m.elements[12] * m.elements[3] * m.elements[5];

    temp[14] = -m.elements[0] * m.elements[5] * m.elements[14] +
        m.elements[0] * m.elements[6] * m.elements[13] +
        m.elements[4] * m.elements[1] * m.elements[14] -
        m.elements[4] * m.elements[2] * m.elements[13] -
        m.elements[12] * m.elements[1] * m.elements[6] +
        m.elements[12] * m.elements[2] * m.elements[5];

    temp[3] = -m.elements[1] * m.elements[6] * m.elements[11] +
        m.elements[1] * m.elements[7] * m.elements[10] +
        m.elements[5] * m.elements[2] * m.elements[11] -
        m.elements[5] * m.elements[3] * m.elements[10] -
        m.elements[9] * m.elements[2] * m.elements[7] +
        m.elements[9] * m.elements[3] * m.elements[6];

    temp[7] = m.elements[0] * m.elements[6] * m.elements[11] -
        m.elements[0] * m.elements[7] * m.elements[10] -
        m.elements[4] * m.elements[2] * m.elements[11] +
        m.elements[4] * m.elements[3] * m.elements[10] +
        m.elements[8] * m.elements[2] * m.elements[7] -
        m.elements[8] * m.elements[3] * m.elements[6];

    temp[11] = -m.elements[0] * m.elements[5] * m.elements[11] +
        m.elements[0] * m.elements[7] * m.elements[9] +
        m.elements[4] * m.elements[1] * m.elements[11] -
        m.elements[4] * m.elements[3] * m.elements[9] -
        m.elements[8] * m.elements[1] * m.elements[7] +
        m.elements[8] * m.elements[3] * m.elements[5];

    temp[15] = m.elements[0] * m.elements[5] * m.elements[10] -
        m.elements[0] * m.elements[6] * m.elements[9] -
        m.elements[4] * m.elements[1] * m.elements[10] +
        m.elements[4] * m.elements[2] * m.elements[9] +
        m.elements[8] * m.elements[1] * m.elements[6] -
        m.elements[8] * m.elements[2] * m.elements[5];

    float determinant = m.elements[0] * temp[0] + m.elements[1] * temp[4] + m.elements[2] * temp[8] + m.elements[3] * temp[12];
    determinant = 1.0f / determinant;

    for (int i = 0; i < 4 * 4; i++)
        res.elements[i] = (float)(temp[i] * (float)determinant);

    return res;
}

gs_inline gs_mat4 
gs_mat4_perspective(f32 fov, f32 asp_ratio, f32 n, f32 f)
{
    // Zero matrix
    gs_mat4 m_res = gs_mat4_ctor();

    f32 q = 1.0f / (float)tan(gs_deg2rad(0.5f * fov));
    f32 a = q / asp_ratio;
    f32 b = (n + f) / (n - f);
    f32 c = (2.0f * n * f) / (n - f);

    m_res.elements[0 + 0 * 4] = a;
    m_res.elements[1 + 1 * 4] = q;
    m_res.elements[2 + 2 * 4] = b;
    m_res.elements[2 + 3 * 4] = c;
    m_res.elements[3 + 2 * 4] = -1.0f;

    return m_res;
}

gs_inline gs_mat4 
gs_mat4_look_at(gs_vec3 position, gs_vec3 target, gs_vec3 up)
{
    gs_vec3 f = gs_vec3_norm(gs_vec3_sub(target, position));
    gs_vec3 s = gs_vec3_norm(gs_vec3_cross(f, up));
    gs_vec3 u = gs_vec3_cross(s, f);

    gs_mat4 m_res = gs_mat4_identity();
    m_res.elements[0 * 4 + 0] = s.x;
    m_res.elements[1 * 4 + 0] = s.y;
    m_res.elements[2 * 4 + 0] = s.z;

    m_res.elements[0 * 4 + 1] = u.x;
    m_res.elements[1 * 4 + 1] = u.y;
    m_res.elements[2 * 4 + 1] = u.z;

    m_res.elements[0 * 4 + 2] = -f.x;
    m_res.elements[1 * 4 + 2] = -f.y;
    m_res.elements[2 * 4 + 2] = -f.z;

    m_res.elements[3 * 4 + 0] = -gs_vec3_dot(s, position);;
    m_res.elements[3 * 4 + 1] = -gs_vec3_dot(u, position);
    m_res.elements[3 * 4 + 2] = gs_vec3_dot(f, position); 

    return m_res;
}

gs_inline
gs_vec4 gs_mat4_mul_vec4(gs_mat4 m, gs_vec4 v)
{
    return gs_vec4_ctor
    (
        m.elements[0 + 4 * 0] * v.x + m.elements[0 + 4 * 1] * v.y + m.elements[0 + 4 * 2] * v.z + m.elements[0 + 4 * 3] * v.w,  
        m.elements[1 + 4 * 0] * v.x + m.elements[1 + 4 * 1] * v.y + m.elements[1 + 4 * 2] * v.z + m.elements[1 + 4 * 3] * v.w,  
        m.elements[2 + 4 * 0] * v.x + m.elements[2 + 4 * 1] * v.y + m.elements[2 + 4 * 2] * v.z + m.elements[2 + 4 * 3] * v.w,  
        m.elements[3 + 4 * 0] * v.x + m.elements[3 + 4 * 1] * v.y + m.elements[3 + 4 * 2] * v.z + m.elements[3 + 4 * 3] * v.w
    );
}

gs_inline
gs_vec3 gs_mat4_mul_vec3(gs_mat4 m, gs_vec3 v)
{
    return gs_v4_to_v3(gs_mat4_mul_vec4(m, gs_v4_xyz_s(v, 1.f)));
    // return gs_v4_to_v3(v4);
    // return gs_vec3_ctor
    // (
    //     m.elements[0 + 4 * 0] * v.x + m.elements[0 + 4 * 1] * v.y + m.elements[0 + 4 * 2] * v.z,  
    //     m.elements[1 + 4 * 0] * v.x + m.elements[1 + 4 * 1] * v.y + m.elements[1 + 4 * 2] * v.z,  
    //     m.elements[2 + 4 * 0] * v.x + m.elements[2 + 4 * 1] * v.y + m.elements[2 + 4 * 2] * v.z
    // );
}
    

/*================================================================================
// Quaternion
================================================================================*/

typedef struct
{
    union 
    {
        gs_vec4 v;
        f32 xyzw[4];
        struct 
        {
            f32 x, y, z, w;
        };
    };
} gs_quat;

gs_inline
gs_quat gs_quat_default()
{
    gs_quat q;
    q.x = 0.f;  
    q.y = 0.f;  
    q.z = 0.f;  
    q.w = 1.f;  
    return q;
}

gs_inline
gs_quat gs_quat_ctor(f32 _x, f32 _y, f32 _z, f32 _w)
{
    gs_quat q;
    q.x = _x;
    q.y = _y;
    q.z = _z;
    q.w = _w;
    return q;
}

gs_inline gs_quat 
gs_quat_add(gs_quat q0, gs_quat q1) 
{
    return gs_quat_ctor(q0.x + q1.x, q0.y + q1.y, q0.z + q1.z, q0.w + q1.w);
}

gs_inline gs_quat 
gs_quat_sub(gs_quat q0, gs_quat q1)
{
    return gs_quat_ctor(q0.x - q1.x, q0.y - q1.y, q0.z - q1.z, q0.w - q1.w);
}

gs_inline gs_quat
gs_quat_mul(gs_quat q0, gs_quat q1)
{
    return gs_quat_ctor(
        q0.w * q1.x + q1.w * q0.x + q0.y * q1.z - q1.y * q0.z,
        q0.w * q1.y + q1.w * q0.y + q0.z * q1.x - q1.z * q0.x,
        q0.w * q1.z + q1.w * q0.z + q0.x * q1.y - q1.x * q0.y,
        q0.w * q1.w - q0.x * q1.x - q0.y * q1.y - q0.z * q1.z
    );
}

gs_inline 
gs_quat gs_quat_mul_list(u32 count, ...)
{
    va_list ap;
    gs_quat q = gs_quat_default();
    va_start(ap, count);
    for (u32 i = 0; i < count; ++i)
    {
        q = gs_quat_mul(q, va_arg(ap, gs_quat));
    }
    va_end(ap);
    return q;
}

gs_inline gs_quat 
gs_quat_mul_quat(gs_quat q0, gs_quat q1)
{
    return gs_quat_ctor(
        q0.w * q1.x + q1.w * q0.x + q0.y * q1.z - q1.y * q0.z,
        q0.w * q1.y + q1.w * q0.y + q0.z * q1.x - q1.z * q0.x,
        q0.w * q1.z + q1.w * q0.z + q0.x * q1.y - q1.x * q0.y,
        q0.w * q1.w - q0.x * q1.x - q0.y * q1.y - q0.z * q1.z
    );
}

gs_inline 
gs_quat gs_quat_scale(gs_quat q, f32 s)
{
    return gs_quat_ctor(q.x * s, q.y * s, q.z * s, q.w * s);
}

gs_inline f32 
gs_quat_dot(gs_quat q0, gs_quat q1)
{
    return (f32)(q0.x * q1.x + q0.y * q1.y + q0.z * q1.z + q0.w * q1.w);
}

gs_inline 
gs_quat gs_quat_conjugate(gs_quat q)
{
    return (gs_quat_ctor(-q.x, -q.y, -q.z, q.w));
}

gs_inline f32
gs_quat_len(gs_quat q)
{
    return (f32)sqrt(gs_quat_dot(q, q));
}

gs_inline gs_quat
gs_quat_norm(gs_quat q) 
{
    return gs_quat_scale(q, 1.0f / gs_quat_len(q));
}

gs_inline gs_quat
gs_quat_cross(gs_quat q0, gs_quat q1)
{
    return gs_quat_ctor (                                           
        q0.x * q1.x + q0.x * q1.w + q0.y * q1.z - q0.z * q1.y,  
        q0.w * q1.y + q0.y * q1.w + q0.z * q1.x - q0.x * q1.z,  
        q0.w * q1.z + q0.z * q1.w + q0.x * q1.y - q0.y * q1.x,  
        q0.w * q1.w - q0.x * q1.x - q0.y * q1.y - q0.z * q1.z   
    );
}

// Inverse := Conjugate / Dot;
gs_inline
gs_quat gs_quat_inverse(gs_quat q)
{
    return (gs_quat_scale(gs_quat_conjugate(q), 1.0f / gs_quat_dot(q, q)));
}

gs_inline gs_vec3 gs_quat_rotate(gs_quat q, gs_vec3 v)
{
    // nVidia SDK implementation
    gs_vec3 qvec = gs_vec3_ctor(q.x, q.y, q.z);
    gs_vec3 uv = gs_vec3_cross(qvec, v);
    gs_vec3 uuv = gs_vec3_cross(qvec, uv);
    uv = gs_vec3_scale(uv, 2.f * q.w);
    uuv = gs_vec3_scale(uuv, 2.f);
    return (gs_vec3_add(v, gs_vec3_add(uv, uuv)));
}

gs_inline gs_quat gs_quat_angle_axis(f32 rad, gs_vec3 axis)
{
    // Normalize axis
    gs_vec3 a = gs_vec3_norm(axis);

    // Get scalar
    f32 half_angle = 0.5f * rad;
    f32 s = (float)sin(half_angle);

    return gs_quat_ctor(a.x * s, a.y * s, a.z * s, (float)cos(half_angle));
}

gs_inline
gs_quat gs_quat_slerp(gs_quat a, gs_quat b, f32 t)
{
    f32 c = gs_quat_dot(a, b);
    gs_quat end = b;

    if (c < 0.0f)
    {
        // Reverse all signs
        c *= -1.0f;
        end.x *= -1.0f;
        end.y *= -1.0f;
        end.z *= -1.0f;
        end.w *= -1.0f;
    }

    // Calculate coefficients
    f32 sclp, sclq;
    if ((1.0f - c) > 0.0001f)
    {
        f32 omega = (float)acosf(c);
        f32 s = (float)sinf(omega);
        sclp = (float)sinf((1.0f - t) * omega) / s;
        sclq = (float)sinf(t * omega) / s; 
    }
    else
    {
        sclp = 1.0f - t;
        sclq = t;
    }

    gs_quat q;
    q.x = sclp * a.x + sclq * end.x;
    q.y = sclp * a.y + sclq * end.y;
    q.z = sclp * a.z + sclq * end.z;
    q.w = sclp * a.w + sclq * end.w;

    return q;
}

#define quat_axis_angle(__AXS, __ANG)\
    gs_quat_angle_axis(__ANG, __AXS)

/*
* @brief Convert given quaternion param into equivalent 4x4 rotation matrix
* @note: From http://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToMatrix/index.htm 
*/
gs_inline gs_mat4 gs_quat_to_mat4(gs_quat _q)
{
    gs_mat4 mat = gs_mat4_identity();
    gs_quat q = gs_quat_norm(_q);

    f32 xx = q.x * q.x; 
    f32 yy = q.y * q.y; 
    f32 zz = q.z * q.z; 
    f32 xy = q.x * q.y;
    f32 xz = q.x * q.z;
    f32 yz = q.y * q.z;
    f32 wx = q.w * q.x;
    f32 wy = q.w * q.y;
    f32 wz = q.w * q.z;

    mat.elements[0 * 4 + 0] = 1.0f - 2.0f * (yy + zz);
    mat.elements[1 * 4 + 0] = 2.0f * (xy - wz);
    mat.elements[2 * 4 + 0] = 2.0f * (xz + wy);

    mat.elements[0 * 4 + 1] = 2.0f * (xy + wz);
    mat.elements[1 * 4 + 1] = 1.0f - 2.0f * (xx + zz);
    mat.elements[2 * 4 + 1] = 2.0f * (yz - wx);

    mat.elements[0 * 4 + 2] = 2.0f * (xz - wy);
    mat.elements[1 * 4 + 2] = 2.0f * (yz + wx);
    mat.elements[2 * 4 + 2] = 1.0f - 2.0f * (xx + yy);

    return mat;
}

gs_inline 
gs_quat gs_quat_from_euler(f32 yaw_deg, f32 pitch_deg, f32 roll_deg)
{
    f32 yaw = gs_deg2rad(yaw_deg);
    f32 pitch = gs_deg2rad(pitch_deg);
    f32 roll = gs_deg2rad(roll_deg);

    gs_quat q;
    f32 cy = (float)cos(yaw * 0.5f);
    f32 sy = (float)sin(yaw * 0.5f);
    f32 cr = (float)cos(roll * 0.5f);
    f32 sr = (float)sin(roll * 0.5f);
    f32 cp = (float)cos(pitch * 0.5f);
    f32 sp = (float)sin(pitch * 0.5f);

    q.x = cy * sr * cp - sy * cr * sp;
    q.y = cy * cr * sp + sy * sr * cp;
    q.z = sy * cr * cp - cy * sr * sp;
    q.w = cy * cr * cp + sy * sr * sp;

    return q;
}

gs_inline
float gs_quat_pitch(gs_quat* q)
{
    return atan2(2.0f * q->y * q->z + q->w * q->x, q->w * q->w - q->x * q->x - q->y * q->y + q->z * q->z);
}

gs_inline
float gs_quat_yaw(gs_quat* q)
{
    return asin(-2.0f * (q->x * q->z - q->w * q->y));
}

gs_inline
float gs_quat_roll(gs_quat* q)
{
    return atan2(2.0f * q->x * q->y +  q->z * q->w,  q->x * q->x + q->w * q->w - q->y * q->y - q->z * q->z);
}

gs_inline
gs_vec3 gs_quat_to_euler(gs_quat* q)
{
    return gs_v3(gs_quat_yaw(q), gs_quat_pitch(q), gs_quat_roll(q));
}

/*================================================================================
// Transform (Non-Uniform Scalar VQS)
================================================================================*/

/*
    - This follows a traditional 'VQS' structure for complex object transformations, 
        however it differs from the standard in that it allows for non-uniform 
        scaling in the form of a vec3.
*/
// Source: https://www.eurosis.org/cms/files/conf/gameon-asia/gameon-asia2007/R-SESSION/G1.pdf

typedef struct 
{
    gs_vec3     position;
    gs_quat     rotation;
    gs_vec3     scale;      
} gs_vqs;

gs_inline gs_vqs gs_vqs_ctor(gs_vec3 tns, gs_quat rot, gs_vec3 scl)
{
    gs_vqs t;   
    t.position = tns;
    t.rotation = rot;
    t.scale = scl;
    return t;
}

gs_inline 
gs_vqs gs_vqs_default()
{
    gs_vqs t = gs_vqs_ctor
    (
        gs_vec3_ctor(0.0f, 0.0f, 0.0f),
        gs_quat_ctor(0.0f, 0.0f, 0.0f, 1.0f),
        gs_vec3_ctor(1.0f, 1.0f, 1.0f)
    );
    return t;
}

// AbsScale = ParentScale * LocalScale
// AbsRot   = LocalRot * ParentRot
// AbsTrans = ParentPos + [ParentRot * (ParentScale * LocalPos)]
gs_inline gs_vqs gs_vqs_absolute_transform(const gs_vqs* local, const gs_vqs* parent)
{
    if (!local || !parent) {
        return gs_vqs_default();
    }

    // Normalized rotations
    gs_quat p_rot_norm = gs_quat_norm(parent->rotation);
    gs_quat l_rot_norm = gs_quat_norm(local->rotation);

    // Scale
    gs_vec3 scl = gs_vec3_mul(local->scale, parent->scale);
    // Rotation
    gs_quat rot = gs_quat_norm(gs_quat_mul(p_rot_norm, l_rot_norm));
    // position
    gs_vec3 tns = gs_vec3_add(parent->position, gs_quat_rotate(p_rot_norm, gs_vec3_mul(parent->scale, local->position)));

    return gs_vqs_ctor(tns, rot, scl);
}

// RelScale = AbsScale / ParentScale 
// RelRot   = Inverse(ParentRot) * AbsRot
// RelTrans = [Inverse(ParentRot) * (AbsPos - ParentPosition)] / ParentScale;
gs_inline gs_vqs gs_vqs_relative_transform(const gs_vqs* absolute, const gs_vqs* parent)
{
    if (!absolute || !parent) {
        return gs_vqs_default();
    }

    // Get inverse rotation normalized
    gs_quat p_rot_inv = gs_quat_norm(gs_quat_inverse(parent->rotation));
    // Normalized abs rotation
    gs_quat a_rot_norm = gs_quat_norm(absolute->rotation);

    // Scale
    gs_vec3 scl = gs_vec3_div(absolute->scale, parent->scale);
    // Rotation
    gs_quat rot = gs_quat_norm(gs_quat_mul(p_rot_inv, a_rot_norm));
    // position
    gs_vec3 tns = gs_vec3_div(gs_quat_rotate(p_rot_inv, gs_vec3_sub(absolute->position, parent->position)), parent->scale);

    return gs_vqs_ctor(tns, rot, scl);
}

gs_inline gs_mat4 gs_vqs_to_mat4(const gs_vqs* transform)
{
    gs_mat4 mat = gs_mat4_identity();
    gs_mat4 trans = gs_mat4_translatev(transform->position);
    gs_mat4 rot = gs_quat_to_mat4(transform->rotation);
    gs_mat4 scl = gs_mat4_scalev(transform->scale);
    mat = gs_mat4_mul(mat, trans);
    mat = gs_mat4_mul(mat, rot);
    mat = gs_mat4_mul(mat, scl);
    return mat;
}

/*================================================================================
// Camera
================================================================================*/

typedef enum gs_projection_type
{
    GS_PROJECTION_TYPE_ORTHOGRAPHIC,
    GS_PROJECTION_TYPE_PERSPECTIVE
} gs_projection_type;

typedef struct gs_camera_t
{
    gs_vqs transform;
    float fov; 
    float aspect_ratio; 
    float near_plane; 
    float far_plane;
    float ortho_scale;
    gs_projection_type proj_type;
} gs_camera_t;

GS_API_DECL gs_camera_t gs_camera_default();
GS_API_DECL gs_camera_t gs_camera_perspective();
GS_API_DECL gs_mat4 gs_camera_get_view(gs_camera_t* cam);
GS_API_DECL gs_mat4 gs_camera_get_proj(gs_camera_t* cam, int32_t view_width, int32_t view_height);
GS_API_DECL gs_mat4 gs_camera_get_view_projection(gs_camera_t* cam, int32_t view_width, int32_t view_height);
GS_API_DECL gs_vec3 gs_camera_forward(gs_camera_t* cam);
GS_API_DECL gs_vec3 gs_camera_backward(gs_camera_t* cam);
GS_API_DECL gs_vec3 gs_camera_up(gs_camera_t* cam);
GS_API_DECL gs_vec3 gs_camera_down(gs_camera_t* cam);
GS_API_DECL gs_vec3 gs_camera_right(gs_camera_t* cam);
GS_API_DECL gs_vec3 gs_camera_left(gs_camera_t* cam);
GS_API_DECL gs_vec3 gs_camera_screen_to_world(gs_camera_t* cam, gs_vec3 coords, int32_t view_width, int32_t view_height);
GS_API_DECL void gs_camera_offset_orientation(gs_camera_t* cam, float yaw, float picth);

/*================================================================================
// Utils
================================================================================*/

// AABBs
/*
    min is top left of rect,
    max is bottom right
*/
/*
typedef struct gs_aabb_t
{
    gs_vec2 min;
    gs_vec2 max;
} gs_aabb_t;

// Collision Resolution: Minimum Translation Vector 
gs_force_inline
gs_vec2 gs_aabb_aabb_mtv(gs_aabb_t* a0, gs_aabb_t* a1)
{
    gs_vec2 diff = gs_v2(a0->min.x - a1->min.x, a0->min.y - a1->min.y);    

    f32 l, r, b, t;
    gs_vec2 mtv = gs_v2(0.f, 0.f);

    l = a1->min.x - a0->max.x;
    r = a1->max.x - a0->min.x;
    b = a1->min.y - a0->max.y;
    t = a1->max.y - a0->min.y;

    mtv.x = fabsf(l) > r ? r : l;
    mtv.y = fabsf(b) > t ? t : b;

    if ( fabsf(mtv.x) <= fabsf(mtv.y)) {
        mtv.y = 0.f;
    } else {
        mtv.x = 0.f;
    }
    
    return mtv;
}

// 2D AABB collision detection (rect. vs. rect.)
gs_force_inline
b32 gs_aabb_vs_aabb(gs_aabb_t* a, gs_aabb_t* b)
{
    if (a->max.x > b->min.x && 
         a->max.y > b->min.y && 
         a->min.x < b->max.x && 
         a->min.y < b->max.y)
    {
        return true;
    }

    return false;
}

gs_force_inline
gs_vec4 gs_aabb_window_coords(gs_aabb_t* aabb, gs_camera_t* camera, gs_vec2 window_size)
{
    // AABB of the player
    gs_vec4 bounds = gs_default_val();
    gs_vec4 tl = gs_v4(aabb->min.x, aabb->min.y, 0.f, 1.f);
    gs_vec4 br = gs_v4(aabb->max.x, aabb->max.y, 0.f, 1.f);

    gs_mat4 view_mtx = gs_camera_get_view(camera);
    gs_mat4 proj_mtx = gs_camera_get_proj(camera, (int32_t)window_size.x, (int32_t)window_size.y);
    gs_mat4 vp = gs_mat4_mul(proj_mtx, view_mtx);

    // Transform verts
    tl = gs_mat4_mul_vec4(vp, tl);            
    br = gs_mat4_mul_vec4(vp, br);

    // Perspective divide   
    tl = gs_vec4_scale(tl, 1.f / tl.w);
    br = gs_vec4_scale(br, 1.f / br.w);

    // NDC [0.f, 1.f] and NDC
    tl.x = (tl.x * 0.5f + 0.5f);
    tl.y = (tl.y * 0.5f + 0.5f);
    br.x = (br.x * 0.5f + 0.5f);
    br.y = (br.y * 0.5f + 0.5f);

    // Window Space
    tl.x = tl.x * window_size.x;
    tl.y = gs_map_range(1.f, 0.f, 0.f, 1.f, tl.y) * window_size.y;
    br.x = br.x * window_size.x;
    br.y = gs_map_range(1.f, 0.f, 0.f, 1.f, br.y) * window_size.y;

    bounds = gs_v4(tl.x, tl.y, br.x, br.y);

    return bounds;
}
*/



