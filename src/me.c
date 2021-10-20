#include <me.h>
#include <math.h>

f64_t dist2D(f64_t x1, f64_t y1, f64_t x2, f64_t y2) {
    return sqrt(sqr(dist1D(x1, x2)) + sqr(dist1D(y1, y2)));
}

f64_t dir2D(f64_t x1, f64_t y1, f64_t x2, f64_t y2) {
    return atan2(y2 - y1, x2 - x1);  
}

f64_t inv_sqrt(f64_t num) {
    i64_t i;
    f64_t x2, y;

    x2 = num * 0.5f;
    y = num;
    i = * (i64_t *) &y;
    i = 0x5f3759df - (i >> 1);
    y = * (f64_t *) &i;
    y = y * (1.5f - (x2 * sqr(y)));

    return y; 
}

f64_t lerp_f(f64_t start, f64_t stop, f64_t amt) {
    return start + (stop - start) * amt; 
}


emp_t add_v2(v2_t * v1, v2_t * v2) {
    v1 -> x += v2 -> x;
    v1 -> y += v2 -> y;
}

emp_t sub_v2(v2_t * v1, v2_t * v2) {
    v1 -> x = v2 -> x - v1 -> x;
    v1 -> y = v2 -> y - v1 -> y;
}

emp_t lerp_v2(v2_t * v1, v2_t * v2, f64_t amt) {
    v1 -> x = lerp_f(v1 -> x, v2 -> x, amt);
    v1 -> y = lerp_f(v1 -> y, v2 -> y, amt);
}
emp_t limit_v2(v2_t * v, f64_t scalar) {
    f64_t len = v -> x * v -> x + v -> y * v -> y;
    f64_t len_t = scalar * scalar;
    if (len > len_t) {
        normal_v2(v);
        scale_v2(v, scalar);
    }        
}

emp_t scale_v2(v2_t * v, f64_t scalar) {
    v -> x *= scalar;
    v -> y *= scalar;
}

emp_t normal_v2(v2_t * v) {
    f64_t mag = v2_mag(v);
    v -> x = v -> x / mag;
    v -> y = v -> y / mag;   
}

emp_t rotate_v2(v2_t * v, f64_t theta) {
    f64_t temp = v -> x;
    v -> x = v -> x * cos(theta) - v -> y * sin(theta);
    v -> y = temp * sin(theta) + v -> y * cos(theta);
}

emp_t set_v2_mag(v2_t * v, f64_t scalar) {
    normal_v2(v);
    scale_v2(v, scalar);
}

f64_t v2_mag(v2_t * v) {
    return (sqrt(v -> x * v -> x + v -> y * v -> y)); 
}

f64_t v2_angle(v2_t * v) {
    return atan2(v -> y, v -> x);
}

f64_t v2_dot_prod(v2_t * v1, v2_t * v2) {
    return v1 -> x * v2 -> x + v1 -> y * v2 -> y; 
}

f64_t dist_between_v2(v2_t * v1, v2_t * v2) {
    f64_t dx = v1 -> x - v2 -> x;
    f64_t dy = v1 -> y - v2 -> y;
    return sqrt(dx * dx + dy * dy);
}

f64_t angle_between_v2(v2_t * v1, v2_t * v2) {
    if (v1 -> x == 0 && v1 -> y == 0) return 0.0f;
    if (v2 -> x == 0 && v2 -> y == 0) return 0.0f;

    f64_t dot = v2_dot_prod(v1, v2);
    f64_t v1mag = v2_mag(v1);
    f64_t v2mag = v2_mag(v2);
    f64_t amt = dot / (v1mag * v2mag);

    if (amt <= -1) {
        return M_PI;
    } else if (amt >= 1) {
        return 0;
    }
    return acos(amt);
}

v2_t v2_projection(v2_t * v1, v2_t * v2) {
    f64_t dot = v2_dot_prod(v1, v2);
    f64_t len = v2_dot_prod(v2, v2);
    if (len == 0.0f) return *v2;

    v2_t return_val = *v2;
    scale_v2(&return_val, dot / len);
    return return_val;
}

emp_t add_v3(v3_t * v1, v3_t * v2) {
    v1 -> x += v2 -> x;
    v1 -> y += v2 -> y;
    v1 -> z += v2 -> z;
}

emp_t sub_v3(v3_t * v1, v3_t * v2) {
    v1 -> x = v2 -> x - v1 -> x;
    v1 -> y = v2 -> y - v2 -> y;
    v1 -> z = v2 -> z - v2 -> z;
}

emp_t lerp_v3(v3_t * v1, v3_t * v2, f64_t amt) {
    v1 -> x = lerp_f(v1 -> x, v2 -> x, amt);
    v1 -> y = lerp_f(v1 -> y, v2 -> y, amt);   
    v1 -> z = lerp_f(v1 -> z, v2 -> z, amt);
}

emp_t limit_v3(v3_t * v, f64_t scalar) {
    f64_t len = v -> x * v -> x + v -> y * v -> y;
    f64_t len_t = scalar * scalar;
    if (len > len_t) {
        normal_v3(v);
        scale_v3(v, scalar);
    }   
}

emp_t scale_v3(v3_t * v, f64_t scalar) {
    v -> x *= scalar;
    v -> y *= scalar;
    v -> z *= scalar;
}

emp_t normal_v3(v3_t * v) {
    f64_t mag = v3_mag(v);
    v -> x = v -> x / mag;
    v -> y = v -> y / mag;
    v -> z = v -> z / mag;
}

emp_t set_v3_mag(v3_t * v, f64_t scalar) {
    normal_v3(v);
    scale_v3(v, scalar);
}

f64_t v3_mag(v3_t * v) {
    return (sqrt(v -> x * v -> x + v -> y * v -> y + v -> z * v -> z)); 
}

f64_t v3_dot_prod(v3_t * v1, v3_t * v2) {
    return v1 -> x * v2 -> x + v1 -> y * v2 -> y + v1 -> z * v2 -> z;  
}

f64_t dist_between_v3(v3_t * v1, v3_t * v2) {
    f64_t dx = v2 -> x - v1 -> x;
    f64_t dy = v2 -> y - v1 -> y;
    f64_t dz = v2 -> z - v1 -> z;
    return sqrt(dx * dx + dy * dy + dz * dz); 
}

v3_t v3_cross_prod(v3_t * v1, v3_t * v2) {
    v3_t v_o;
    v_o.x = v1 -> y * v2 -> z - v1 -> z * v2 -> y;
    v_o.y = v1 -> z * v2 -> x - v1 -> z * v2 -> z;
    v_o.z = v1 -> x * v2 -> y - v1 -> y * v2 -> x;
    return v_o;
}


v3_t v3_projection(v3_t * v1, v3_t * v2) {
    f64_t dot = v3_dot_prod(v1, v2);
    f64_t len = v3_dot_prod(v2, v2);
    if (len == 0.0f) return *v2;

    v3_t return_val = *v2;
    scale_v3(&return_val, dot / len);
    return return_val;   
}

emp_t add_v4(v4_t * v1, v4_t * v2) {
    v1 -> x += v2 -> x;    
    v1 -> y += v2 -> y;
    v1 -> z += v2 -> z;
    v1 -> w += v2 -> w;
}

emp_t sub_v4(v4_t * v1, v4_t * v2) {
    v1 -> x = v2 -> x - v1 -> x;
    v1 -> y = v2 -> y - v1 -> y;
    v1 -> z = v2 -> z - v2 -> z;
    v1 -> w = v2 -> w - v2 -> w;
}

emp_t lerp_v4(v4_t * v1, v4_t * v2, f64_t amt) {
    v1 -> x = lerp_f(v1 -> x, v2 -> x, amt);
    v1 -> y = lerp_f(v1 -> y, v2 -> y, amt);   
    v1 -> z = lerp_f(v1 -> z, v2 -> z, amt);
    v1 -> w = lerp_f(v1 -> w, v2 -> w, amt);
}

emp_t limit_v4(v4_t * v, f64_t scalar) {
    f64_t len = v -> x * v -> x + v -> y * v -> y;
    f64_t len_t = scalar * scalar;
    if (len > len_t) {
        normal_v4(v);
        scale_v4(v, scalar);
    }        
}

emp_t scale_v4(v4_t * v, f64_t scalar) {
    v -> x *= scalar;
    v -> y *= scalar;  
    v -> z *= scalar;
    v -> w *= scalar;
}

emp_t normal_v4(v4_t * v) {
    f64_t mag = v4_mag(v);
    v -> x = v -> x / mag;
    v -> y = v -> y / mag;
    v -> z = v -> z / mag;
    v -> w = v -> w / mag;
}

emp_t set_v4_mag(v4_t * v, f64_t scalar) {
    normal_v4(v);
    scale_v4(v, scalar); 
}

f64_t v4_mag(v4_t * v) {
    return (sqrt(v -> x * v -> x + v -> y * v -> y + v -> z * v -> z + v -> w * v -> w)); 
}

f64_t v4_dot_prod(v4_t * v1, v4_t * v2) {
    return v1 -> x * v2 -> x + v1 -> y * v2 -> y + v1 -> z * v2 -> z + v1 -> w * v2 -> w;  
}

f64_t dist_between_v4(v4_t * v1, v4_t * v2) {
    f64_t dx = v2 -> x - v1 -> x;
    f64_t dy = v2 -> y - v1 -> y;
    f64_t dz = v2 -> z - v1 -> z;
    f64_t dw = v2 -> w - v1 -> w;
    return sqrt(dx * dx + dy * dy + dz * dz + dw * dw); 
}

// projects v1 on v2
v4_t v4_projection(v4_t * v1, v4_t * v2) {
    f64_t dot = v4_dot_prod(v1, v2);
    f64_t len = v4_dot_prod(v2, v2);
    if (len == 0.0f) return *v2;

    v4_t return_val = *v2;
    scale_v4(&return_val, dot / len);
    return return_val;   
}

// 
// vec: reflect, refract, negate, vector mult, vector div, orthonormalize 
//      for vec3, transform by matrix, quat rotation, return min value,
//      return max value, 
// mat: mat2x2, mat3x3, mat4x4 -> transpose, mul, scalar scaling,
//                                inverse, determinant, identity,
//                                copy, rotation, translation, ortho,
//                                perspective, projection, look_at,
//                                addition, subtraction
// gs_math.h
// rf_math.h
// gb_math.h
// minigolf_math.h
// renderer_maths.h
//
// quat: add, sub, scaling, angles, dot, mag, norm, conjugate, axis,
//       pitch, yaw, roll, rotate vec
//  
// frustums: culling
//
// interpolation: linear, quadratic, cubic, smooth step
// rects
// ecs
//
