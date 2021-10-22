#include <me.h>
#include <math.h>
#include <stdlib.h>

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

f64_t ilerp(f64_t start, f64_t stop, f64_t amt) {
    return start + (stop - start) * amt; 
}

i64_t randnum_gen(i64_t lower, i64_t upper) {
    return (rand() % (upper - lower + 1)) + lower;
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
    v1 -> x = ilerp(v1 -> x, v2 -> x, amt);
    v1 -> y = ilerp(v1 -> y, v2 -> y, amt);
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

    if (mag != 1.0f) {
        v -> x = v -> x / mag;
        v -> y = v -> y / mag;  
    }
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

emp_t negate_v2 (v2_t * v) {
    v -> x = -v -> x;
    v -> y = -v -> y;
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
    v1 -> x = ilerp(v1 -> x, v2 -> x, amt);
    v1 -> y = ilerp(v1 -> y, v2 -> y, amt);   
    v1 -> z = ilerp(v1 -> z, v2 -> z, amt);
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


    if (mag != 1.0f) {
        v -> x = v -> x / mag;
        v -> y = v -> y / mag;
        v -> z = v -> z / mag;
        
    }
}

emp_t set_v3_mag(v3_t * v, f64_t scalar) {
    normal_v3(v);
    scale_v3(v, scalar);
}

emp_t negate_v3(v3_t * v) {
    v -> x = -v -> x;
    v -> y = -v -> y;
    v -> z = -v -> z;
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
    v1 -> x = ilerp(v1 -> x, v2 -> x, amt);
    v1 -> y = ilerp(v1 -> y, v2 -> y, amt);   
    v1 -> z = ilerp(v1 -> z, v2 -> z, amt);
    v1 -> w = ilerp(v1 -> w, v2 -> w, amt);
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
    if (mag != 1.0f) {
        v -> x = v -> x / mag;
        v -> y = v -> y / mag;
        v -> z = v -> z / mag;
        v -> w = v -> w / mag;
    }
}

emp_t set_v4_mag(v4_t * v, f64_t scalar) {
    normal_v4(v);
    scale_v4(v, scalar); 
}

emp_t negate_v4(v4_t * v) {
    v -> x = -v -> x;
    v -> y = -v -> y;
    v -> z = -v -> z;
    v -> w = -v -> w;
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

m4x4_t mk_m4x4(f64_t m01, f64_t m02, f64_t m03, f64_t m04, 
               f64_t m05, f64_t m06, f64_t m07, f64_t m08,
               f64_t m09, f64_t m10, f64_t m11, f64_t m12, 
               f64_t m13, f64_t m14, f64_t m15, f64_t m16) {
    m4x4_t mat;

    mat.mat[0] = m01;
    mat.mat[1] = m02;
    mat.mat[2] = m03; 
    mat.mat[3] = m04;

    mat.mat[4] = m05;
    mat.mat[5] = m06;
    mat.mat[6] = m07;
    mat.mat[7] = m08;

    mat.mat[8] = m09;
    mat.mat[9] = m10;
    mat.mat[10] = m11;
    mat.mat[11] = m12;

    mat.mat[12] = m13;
    mat.mat[13] = m14;
    mat.mat[14] = m15;
    mat.mat[15] = m16;

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

m4x4_t diag_m4x4(f64_t val) {
	m4x4_t mat = {0};
	mat.mat[0 + 0 * 4] = val;
	mat.mat[1 + 1 * 4] = val;
	mat.mat[2 + 2 * 4] = val;
	mat.mat[3 + 3 * 4] = val;
	return mat;
}

emp_t m4x4_add(m4x4_t * m1, m4x4_t * m2) {
    for (i16_t i = 0; i < 16; i++) {
        m1 -> mat[i] += m2 -> mat[i];
    }
}


emp_t m4x4_sub(m4x4_t * m1, m4x4_t * m2) {
    for (i16_t i = 0; i < 16; i++) {
        m2 -> mat[i] -= m1 -> mat[i];
    }
} 

m4x4_t m4x4_mult(m4x4_t m1, m4x4_t m2) {
 	m4x4_t result = zero_m4x4(); 
	for (u32_t y = 0; y < 4; ++y) {
		for (u32_t x = 0; x < 4; ++x) {
			f32_t sum = 0.0f;
			for (u32_t e = 0; e < 4; ++e) {
				sum += m1.mat[x + e * 4] * m2.mat[e + y * 4];
			}
			result.mat[x + y * 4] = sum;
		}
	}

	return result;
} 

emp_t scale_m4x4_by_v3(m4x4_t * mat, const v3_t vector) {
    mat -> mat[0] *= vector.x;
    mat -> mat[5] *= vector.y;
    mat -> mat[10] *= vector.z;
}

// Takes in an identity matrix
m4x4_t translate_m4x4(m4x4_t mat, const v3_t vector) {
    mat.mat[12] += vector.x;
    mat.mat[13] += vector.y;
    mat.mat[14] += vector.z;
    return mat;
}

m4x4_t m4x4_rotate(f32_t degrees, v3_t axis) {

    m4x4_t mat = identity_m4x4();

    float a = degrees;
    float c = (float)cos(a);
    float s = (float)sin(a);

    normal_v3(&axis);
    float x = axis.x;
    float y = axis.y;
    float z = axis.z;

    //First column
    mat.mat[0 + 0 * 4] = x * x * (1 - c) + c;    
    mat.mat[1 + 0 * 4] = x * y * (1 - c) + z * s;    
    mat.mat[2 + 0 * 4] = x * z * (1 - c) - y * s;    

    //Second column
    mat.mat[0 + 1 * 4] = x * y * (1 - c) - z * s;    
    mat.mat[1 + 1 * 4] = y * y * (1 - c) + c;    
    mat.mat[2 + 1 * 4] = y * z * (1 - c) + x * s;    

    //Third column
    mat.mat[0 + 2 * 4] = x * z * (1 - c) + y * s;    
    mat.mat[1 + 2 * 4] = y * z * (1 - c) - x * s;    
    mat.mat[2 + 2 * 4] = z * z * (1 - c) + c;    

    return mat;

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

emp_t get_gl_matrix(m4x4_t * m) {
    m -> matrix[0][0] = m -> mat[0];
    m -> matrix[0][1] = m -> mat[1];
    m -> matrix[0][2] = m -> mat[2];
    m -> matrix[0][3] = m -> mat[3];
    m -> matrix[1][0] = m -> mat[4];
    m -> matrix[1][1] = m -> mat[5];
    m -> matrix[1][2] = m -> mat[6];
    m -> matrix[1][3] = m -> mat[7];
    m -> matrix[2][0] = m -> mat[8];
    m -> matrix[2][1] = m -> mat[9];
    m -> matrix[2][2] = m -> mat[10];
    m -> matrix[2][3] = m -> mat[11];
    m -> matrix[3][0] = m -> mat[12];
    m -> matrix[3][1] = m -> mat[13];
    m -> matrix[3][2] = m -> mat[14];
    m -> matrix[3][3] = m -> mat[15];
}

