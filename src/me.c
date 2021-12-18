#include <me.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>

f32_t dist2D(f32_t x1, f32_t y1, f32_t x2, f32_t y2) {
    return sqrt(sqr(dist1D(x1, x2)) + sqr(dist1D(y1, y2)));
}

f32_t dir2D(f32_t x1, f32_t y1, f32_t x2, f32_t y2) {
    return atan2(y2 - y1, x2 - x1);  
}

f32_t inv_sqrt(f32_t num) {
    i64_t i;
    f32_t x2, y;

    x2 = num * 0.5f;
    y = num;
    i = * (i64_t *) &y;
    i = 0x5f3759df - (i >> 1);
    y = * (f32_t *) &i;
    y = y * (1.5f - (x2 * sqr(y)));

    return y; 
}

f32_t ilerp(f32_t start, f32_t stop, f32_t amt) {
    return start + (stop - start) * amt; 
}

i64_t randnum_gen(i64_t lower, i64_t upper) {
    return (rand() % (upper - lower + 1)) + lower;
}


v2_t * mk_v2_ptr(f32_t x, f32_t y) {
    v2_t * v = calloc(1, sizeof(v2_t));
    v -> x = x;
    v -> y = y;
    return v;
}

emp_t add_v2(v2_t * v1, v2_t * v2) {
    v1 -> x += v2 -> x;
    v1 -> y += v2 -> y;
}

emp_t sub_v2(v2_t * v1, v2_t * v2) {
    v1 -> x -= v2 -> x;
    v1 -> y -= v2 -> y;
}

emp_t lerp_v2(v2_t * v1, v2_t * v2, f32_t amt) {
    v1 -> x = ilerp(v1 -> x, v2 -> x, amt);
    v1 -> y = ilerp(v1 -> y, v2 -> y, amt);
}
emp_t limit_v2(v2_t * v, f32_t scalar) {
    f32_t len = v -> x * v -> x + v -> y * v -> y;
    f32_t len_t = scalar * scalar;
    if (len > len_t) {
        normal_v2(v);
        scale_v2(v, scalar);
    }        
}

emp_t scale_v2(v2_t * v, f32_t scalar) {
    v -> x *= scalar;
    v -> y *= scalar;
}

emp_t normal_v2(v2_t * v) {
    f32_t mag = v2_mag(v);

    if (mag != 1.0f) {
        v -> x = v -> x / mag;
        v -> y = v -> y / mag;  
    }
}


emp_t rotate_v2(v2_t * v, f32_t theta) {
    f32_t temp = v -> x;
    v -> x = v -> x * cos(theta) - v -> y * sin(theta);
    v -> y = temp * sin(theta) + v -> y * cos(theta);
}

emp_t set_v2_mag(v2_t * v, f32_t scalar) {
    normal_v2(v);
    scale_v2(v, scalar);
}

emp_t negate_v2 (v2_t * v) {
    v -> x = -v -> x;
    v -> y = -v -> y;
}

f32_t v2_mag(v2_t * v) {
    return (sqrt(v -> x * v -> x + v -> y * v -> y)); 
}

f32_t v2_angle(v2_t * v) {
    return atan2(v -> y, v -> x);
}

f32_t v2_dot_prod(v2_t * v1, v2_t * v2) {
    return v1 -> x * v2 -> x + v1 -> y * v2 -> y; 
}

f32_t dist_between_v2(v2_t * v1, v2_t * v2) {
    f32_t dx = v1 -> x - v2 -> x;
    f32_t dy = v1 -> y - v2 -> y;
    return sqrt(dx * dx + dy * dy);
}

f32_t angle_between_v2(v2_t * v1, v2_t * v2) {
    if (v1 -> x == 0 && v1 -> y == 0) return 0.0f;
    if (v2 -> x == 0 && v2 -> y == 0) return 0.0f;

    f32_t dot = v2_dot_prod(v1, v2);
    f32_t v1mag = v2_mag(v1);
    f32_t v2mag = v2_mag(v2);
    f32_t amt = dot / (v1mag * v2mag);

    if (amt <= -1) {
        return M_PI;
    } else if (amt >= 1) {
        return 0;
    }
    return acos(amt);
}

v2_t v2_projection(v2_t * v1, v2_t * v2) {
    f32_t dot = v2_dot_prod(v1, v2);
    f32_t len = v2_dot_prod(v2, v2);
    if (len == 0.0f) return *v2;

    v2_t return_val = *v2;
    scale_v2(&return_val, dot / len);
    return return_val;
}

v3_t * mk_v3_ptr(f32_t x, f32_t y, f32_t z) {
    v3_t * v = calloc(1, sizeof(v3_t));
    v -> x = x;
    v -> y = y;
    v -> z = z;
    return v;
}


emp_t add_v3(v3_t * v1, v3_t * v2) {
    v1 -> x += v2 -> x;
    v1 -> y += v2 -> y;
    v1 -> z += v2 -> z;
}

emp_t sub_v3(v3_t * v1, v3_t * v2) {
    v1 -> x -= v2 -> x;
    v1 -> y -= v2 -> y;
    v1 -> z -= v2 -> z;
}

emp_t lerp_v3(v3_t * v1, v3_t * v2, f32_t amt) {
    v1 -> x = ilerp(v1 -> x, v2 -> x, amt);
    v1 -> y = ilerp(v1 -> y, v2 -> y, amt);   
    v1 -> z = ilerp(v1 -> z, v2 -> z, amt);
}

emp_t limit_v3(v3_t * v, f32_t scalar) {
    f32_t len = v -> x * v -> x + v -> y * v -> y;
    f32_t len_t = scalar * scalar;
    if (len > len_t) {
        normal_v3(v);
        scale_v3(v, scalar);
    }   
}

emp_t scale_v3(v3_t * v, f32_t scalar) {
    v -> x *= scalar;
    v -> y *= scalar;
    v -> z *= scalar;
}

emp_t normal_v3(v3_t * v) {
    f32_t mag = v3_mag(v);


    if (mag != 1.0f) {
        v -> x = v -> x / mag;
        v -> y = v -> y / mag;
        v -> z = v -> z / mag;
        
    }
}

emp_t set_v3_mag(v3_t * v, f32_t scalar) {
    normal_v3(v);
    scale_v3(v, scalar);
}

emp_t negate_v3(v3_t * v) {
    v -> x = -v -> x;
    v -> y = -v -> y;
    v -> z = -v -> z;
}

f32_t v3_mag(v3_t * v) {
    return (sqrt(v -> x * v -> x + v -> y * v -> y + v -> z * v -> z)); 
}

f32_t v3_dot_prod(v3_t * v1, v3_t * v2) {
    return v1 -> x * v2 -> x + v1 -> y * v2 -> y + v1 -> z * v2 -> z;  
}

f32_t dist_between_v3(v3_t * v1, v3_t * v2) {
    f32_t dx = v2 -> x - v1 -> x;
    f32_t dy = v2 -> y - v1 -> y;
    f32_t dz = v2 -> z - v1 -> z;
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
    f32_t dot = v3_dot_prod(v1, v2);
    f32_t len = v3_dot_prod(v2, v2);
    if (len == 0.0f) return *v2;

    v3_t return_val = *v2;
    scale_v3(&return_val, dot / len);
    return return_val;   
}

f32_t angle_between_v3(v3_t * v1, v3_t * v2) {
    if (v1 -> x == 0 && v1 -> y == 0) return 0.0f;
    if (v2 -> x == 0 && v2 -> y == 0) return 0.0f;
    if (v2 -> z == 0 && v2 -> z == 0) return 0.0f;

    f32_t dot = v3_dot_prod(v1, v2);
    f32_t v1mag = v3_mag(v1);
    f32_t v2mag = v3_mag(v2);
    f32_t amt = dot / (v1mag * v2mag);

    if (amt <= -1) {
        return M_PI;
    } else if (amt >= 1) {
        return 0;
    }
    return acos(amt);   
}

v4_t * mk_v4_ptr(f32_t x, f32_t y, f32_t z, f32_t w) {
    v4_t * v = calloc(1, sizeof(v4_t));
    v -> x = x;
    v -> y = y;
    v -> z = z;
    v -> w = w;
    return v;
}


emp_t add_v4(v4_t * v1, v4_t * v2) {
    v1 -> x += v2 -> x;    
    v1 -> y += v2 -> y;
    v1 -> z += v2 -> z;
    v1 -> w += v2 -> w;
}

emp_t sub_v4(v4_t * v1, v4_t * v2) {
    v1 -> x -= v2 -> x;
    v1 -> y -= v2 -> y;
    v1 -> z -= v2 -> z;
    v1 -> w -= v2 -> w;
}

emp_t lerp_v4(v4_t * v1, v4_t * v2, f32_t amt) {
    v1 -> x = ilerp(v1 -> x, v2 -> x, amt);
    v1 -> y = ilerp(v1 -> y, v2 -> y, amt);   
    v1 -> z = ilerp(v1 -> z, v2 -> z, amt);
    v1 -> w = ilerp(v1 -> w, v2 -> w, amt);
}

emp_t limit_v4(v4_t * v, f32_t scalar) {
    f32_t len = v -> x * v -> x + v -> y * v -> y;
    f32_t len_t = scalar * scalar;
    if (len > len_t) {
        normal_v4(v);
        scale_v4(v, scalar);
    }        
}

emp_t scale_v4(v4_t * v, f32_t scalar) {
    v -> x *= scalar;
    v -> y *= scalar;  
    v -> z *= scalar;
    v -> w *= scalar;
}

emp_t normal_v4(v4_t * v) {
    f32_t mag = v4_mag(v);
    if (mag != 1.0f) {
        v -> x = v -> x / mag;
        v -> y = v -> y / mag;
        v -> z = v -> z / mag;
        v -> w = v -> w / mag;
    }
}

emp_t set_v4_mag(v4_t * v, f32_t scalar) {
    normal_v4(v);
    scale_v4(v, scalar); 
}

emp_t negate_v4(v4_t * v) {
    v -> x = -v -> x;
    v -> y = -v -> y;
    v -> z = -v -> z;
    v -> w = -v -> w;
}




f32_t v4_mag(v4_t * v) {
    return (sqrt(v -> x * v -> x + v -> y * v -> y + v -> z * v -> z + v -> w * v -> w)); 
}

f32_t v4_dot_prod(v4_t * v1, v4_t * v2) {
    return v1 -> x * v2 -> x + v1 -> y * v2 -> y + v1 -> z * v2 -> z + v1 -> w * v2 -> w;  
}

f32_t dist_between_v4(v4_t * v1, v4_t * v2) {
    f32_t dx = v2 -> x - v1 -> x;
    f32_t dy = v2 -> y - v1 -> y;
    f32_t dz = v2 -> z - v1 -> z;
    f32_t dw = v2 -> w - v1 -> w;
    return sqrt(dx * dx + dy * dy + dz * dz + dw * dw); 
}

// projects v1 on v2
v4_t v4_projection(v4_t * v1, v4_t * v2) {
    f32_t dot = v4_dot_prod(v1, v2);
    f32_t len = v4_dot_prod(v2, v2);
    if (len == 0.0f) return *v2;

    v4_t return_val = *v2;
    scale_v4(&return_val, dot / len);
    return return_val;   
}

v3_t v2_to_v3(const v2_t v) {
    return mk_v3(v.x, v.y, 1);
}

v4_t v3_to_v4(const v3_t v) {
    return mk_v4(v.x, v.y, v.z, 1);
}

v3_t v4_to_v3(const v4_t v) {
    return mk_v3(v.x, v.y, v.z);
}

v2_t v3_to_v2(const v3_t v) {
    return mk_v2(v.x, v.y);
}


m4x4_t mk_m4x4(f32_t m00, f32_t m01, f32_t m02, f32_t m03,
               f32_t m04, f32_t m05, f32_t m06, f32_t m07,
               f32_t m08, f32_t m09, f32_t m10, f32_t m11,
               f32_t m12, f32_t m13, f32_t m14, f32_t m15) { 
    m4x4_t mat = {{
        {m00, m01, m02, m03},
        {m04, m05, m06, m07},
        {m08, m09, m10, m11},
        {m12, m13, m14, m15}
    }};

    return mat;
}

m4x4_t zero_m4x4() {
    return mk_m4x4( 
                    0, 0, 0, 0,
                    0, 0, 0, 0, 
                    0, 0, 0, 0, 
                    0, 0, 0, 0
                  );
}

m4x4_t identity_m4x4() {
    return mk_m4x4(
                     1, 0, 0, 0,
                     0, 1, 0, 0,
                     0, 0, 1, 0,
                     0, 0, 0, 1
                    
                  );
}

m4x4_t diag_m4x4(f32_t val) {
    return mk_m4x4(
                    val, 000, 000, 000,
                    000, val, 000, 000,
                    000, 000, val, 000,
                    000, 000, 000, val
                  );
}

emp_t m4x4_add(m4x4_t * m1, m4x4_t * m2) {
    for (u16_t i = 0; i < 4; i++) {
        for (u16_t j = 0; j < 4; j++) {
            m1 -> elems[i][j] += m2 -> elems[i][j];
        }
    }
}

emp_t m4x4_sub(m4x4_t * m1, m4x4_t * m2) {
    for (u16_t i = 0; i < 4; i++) {
        for (u16_t j = 0; j < 4; j++) {
            m2 -> elems[i][j] -= m1 -> elems[i][j];
        }
    }
} 
m4x4_t m4x4_mult(m4x4_t m1, m4x4_t m2) {
 	m4x4_t result = zero_m4x4(); 
	for (u32_t y = 0; y < 4; ++y) {
		for (u32_t x = 0; x < 4; ++x) {
			f32_t sum = 0.0f;
			for (u32_t e = 0; e < 4; ++e) {
				sum += m1.elems[e][x] * m2.elems[y][e];
			}
			result.elems[y][x] = sum;
		}
	}

	return result;
} 

m4x4_t scale_m4x4_by_v3(m4x4_t mat, const v3_t vector) {
    mat.elems[0][0] *= vector.x;
    mat.elems[1][1] *= vector.y;
    mat.elems[2][2] *= vector.z;
    return mat;
}

// Takes in an identity matrix
m4x4_t translate_m4x4(m4x4_t mat, const v3_t vector) {
    mat.elems[3][0] += vector.x;
    mat.elems[3][1] += vector.y;
    mat.elems[3][2] += vector.z;
    return mat;
}

m4x4_t m4x4_rotate(f32_t degrees, v3_t axis) {
    m4x4_t mat = identity_m4x4();

    f32_t a = degrees;
    f32_t c = (f32_t)cos(a);
    f32_t s = (f32_t)sin(a);

    normal_v3(&axis);
    f32_t x = axis.x;
    f32_t y = axis.y;
    f32_t z = axis.z;

    //First column
    mat.elems[0][0] = c + (x * x) * (1 - c);
    mat.elems[0][1] = x * y * (1 - c) - (z * s);
    mat.elems[0][2] = x * z * (1 - c) + (y * s);

    //Second column
    mat.elems[1][0] = y * x * (1 - c) + z * s;
    mat.elems[1][1] = c + y * y * (1 - c);
    mat.elems[1][2] = y * z * (1 - c) - x * s;

    //Third column
    mat.elems[2][0] = z * x * (1 - c) - y * s;
    mat.elems[2][1] = z * y * (1 - c) + x * s;
    mat.elems[2][2] = c + z * z * (1 - c);

    return mat;

}

m4x4_t m4x4_mult_n(u32_t m4x4_count, ...) {
    va_list matrices;
    va_start(matrices, m4x4_count);
        m4x4_t ident = identity_m4x4();
        for (u32_t i = 0; i < m4x4_count; ++i) {
            ident = m4x4_mult(ident, va_arg(matrices, m4x4_t));
        }

    va_end(matrices);

    return ident;
}


v4_t m4x4_mult_v4(m4x4_t m, v4_t v) {
    return mk_v4(
                m.elems[0][0] * v.x + m.elems[1][0] * v.y + m.elems[2][0] * v.z + m.elems[3][0] * v.w,  
                m.elems[0][1] * v.x + m.elems[1][1] * v.y + m.elems[2][1] * v.z + m.elems[3][1] * v.w,  
                m.elems[0][2] * v.x + m.elems[1][2] * v.y + m.elems[2][2] * v.z + m.elems[3][2] * v.w,  
                m.elems[0][3] * v.x + m.elems[1][3] * v.y + m.elems[2][3] * v.z + m.elems[3][3] * v.w
         );
}


v3_t m4x4_mult_v3(m4x4_t m, v3_t v) {
    return v4_to_v3(m4x4_mult_v4(m, mk_v4(v.x, v.y, v.z, 1)));
}


m4x4_t mk_ortho_projection_m4x4(f32_t l, f32_t r, f32_t b, f32_t t, f32_t n, f32_t f) {
    return mk_m4x4
    (
        
        2.0f / (r - l), 0, 0,  0,
        0, +2.0f / (t - b), 0, 0,
        0, 0, -2.0f / (f - n), 0,
        -(r + l) / (r - l), -(t + b) / (t - b), -(f + n) / (f - n), 1.0f
               
    );
}



m4x4_t mk_perspective_projection_m4x4(f32_t fov, f32_t asp_ratio, f32_t n, f32_t f) {
    m4x4_t result = zero_m4x4(); 

    f32_t q = 1.0f / (f32_t)tan(deg_to_rad(0.5f * fov));
    f32_t a = q / asp_ratio;
    f32_t b = (n + f) / (n - f);
    f32_t c = (2.0f * n * f) / (n - f);

    result.elems[0][0] = a;
    result.elems[1][1] = q;
    result.elems[2][2] = b;
    result.elems[3][2] = c;
    result.elems[3][3] = -1.0f;

    // a, 0, 0,  0,
    // 0, q, 0,  0,
    // 0, 0, b,  0,
    // 0, 0, c, -1
    return result;
}


m4x4_t m4x4_lookat(v3_t pos, v3_t target, v3_t up) {
    sub_v3(&target, &pos);
    normal_v3(&target);
    v3_t f = target; 

    v3_t s = v3_cross_prod(&f, &up);
    normal_v3(&s);

    v3_t u = v3_cross_prod(&s, &f);

    m4x4_t result = identity_m4x4();
    result.elems[0][0] = s.x;
    result.elems[1][0] = s.y;
    result.elems[2][0] = s.z;

    result.elems[0][1] = u.x;
    result.elems[1][1] = u.y;
    result.elems[2][1] = u.z;

    result.elems[0][2] = -f.x;
    result.elems[1][2] = -f.y;
    result.elems[2][2] = -f.z;

    result.elems[3][0] = -v3_dot_prod(&s, &pos);;
    result.elems[3][1] = -v3_dot_prod(&u, &pos);
    result.elems[3][2] = v3_dot_prod(&f, &pos); 

    return result;   
}
