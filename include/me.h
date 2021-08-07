#ifndef _C_STD_ME

    #define _C_STD_ME
    
    #include <types.h>
   
    /// ??? = help needed
    // Just a little context, f64 is a 64-bit float, aka double while f32 which you barely see is the normal form of floats in C

    #define std_pi 3.14159265358979
    #define std_deg_to_rad(deg) deg * (std_pi / 180)
    #define std_rad_to_deg(rad) rad * (180 / std_pi)
    #define std_sqr(e) e * e
    #define std_dist_1d(c1, c2) c2 - c1
   
    f64 std_dist_2d (f64 x1, f64 y1, f64 x2, f64 y2);
    f64 std_dir_2d  (f64 x1, f64 y1, f64 x2, f64 y2);
    f64 std_inv_sqrt(f64 num);
    f64 std_lerp_f  (f64 start, f64 stop, f64 amt);
   
    typedef struct {
        f64 x;
        f64 y;
    } std_vec2_t;

    #define std_v2_zero() { .x = 0.0f, .y = 0.0f };
    #define std_v2_one () { .x = 1.0f, .y = 1.0f };
    #define std_v2(_x, _y) { .x = _x, .y = _y };

    emp init_std_vec2_t   (std_vec2_t * v, f64 x, f64 y);    
    emp add_std_vec2_t    (std_vec2_t * v1, std_vec2_t * v2);
    emp sub_std_vec2_t    (std_vec2_t * v1, std_vec2_t * v2);
    emp lerp_std_vec2_t   (std_vec2_t * v1, std_vec2_t * v2, f64 amt);
    emp limit_std_vec2_t  (std_vec2_t * v, f64 scalar);
    emp scale_std_vec2_t  (std_vec2_t * v, f64 scalar);
    emp normal_std_vec2_t (std_vec2_t * v);
    emp rotate_std_vec2_t (std_vec2_t * v, f64 theta);
    emp set_std_vec2_t_mag(std_vec2_t * v, f64 scalar);

    f64 get_std_vec2_t_mag         (std_vec2_t * v);
    f64 get_angle_std_vec2_t       (std_vec2_t * v);
    f64 get_dot_prod_std_vec2_t    (std_vec2_t * v1, std_vec2_t * v2);
    f64 get_dist_between_std_vec2_t(std_vec2_t * v1, std_vec2_t * v2);
    f64 get_angle_of_two_std_vec2_t(std_vec2_t * v1, std_vec2_t * v2);

    std_vec2_t project_on_std_vec2_t(std_vec2_t * v1, std_vec2_t * v2);

    typedef struct {
        f64 x;
        f64 y;
        f64 z;
    } std_vec3_t;

    #define std_v3_zero() { .x = 0.0f, .y = 0.0f, .z = 0.0f };
    #define std_v3_one () { .x = 1.0f, .y = 1.0f, .z = 1.0f };
    #define std_v3(x, y, z) { .x = x, .y = y, .z = z };

    emp init_std_vec3_t   (std_vec3_t * v, f64 x, f64 y, f64 z);    
    emp add_std_vec3_t    (std_vec3_t * v1, std_vec3_t * v2);
    emp sub_std_vec3_t    (std_vec3_t * v1, std_vec3_t * v2);
    emp lerp_std_vec3_t   (std_vec3_t * v1, std_vec3_t * v2, f64 amt);
    emp limit_std_vec3_t  (std_vec3_t * v, f64 scalar);
    emp scale_std_vec3_t  (std_vec3_t * v, f64 scalar);
    emp normal_std_vec3_t (std_vec3_t * v);
    emp set_std_vec3_t_mag(std_vec3_t * v, f64 scalar);
    
    f64 get_std_vec3_t_mag         (std_vec3_t * v);
    f64 get_dot_prod_std_vec3_t    (std_vec3_t * v1, std_vec3_t * v2);
    f64 get_dist_between_std_vec3_t(std_vec3_t * v1, std_vec3_t * v2); 

    std_vec3_t get_cross_prod_std_vec3_t(std_vec3_t * v1, std_vec3_t * v2);
    // projects v1 on v2
    std_vec3_t project_on_std_vec3_t    (std_vec3_t * v1, std_vec3_t * v2);

    typedef struct {
        f64 x;
        f64 y;
        f64 z;
        f64 w;
    } std_vec4_t; // The size of a vec4 will be around 8 * 4 = 32 bytes, I am contemplating now whether I should use f64 or not

    #define std_v4_zero() { .x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f };
    #define std_v4_one () { .x = 1.0f, .y = 1.0f, .z = 1.0f, .w = 1.0f };
    #define std_v4(x, y, z, w) { .x = x, .y = y, .z = z, .w = w };

    emp init_std_vec4_t   (std_vec4_t * v, f64 x, f64 y, f64 z, f64 w);    
    emp add_std_vec4_t    (std_vec4_t * v1, std_vec4_t * v2);
    emp sub_std_vec4_t    (std_vec4_t * v1, std_vec4_t * v2);
    emp lerp_std_vec4_t   (std_vec4_t * v1, std_vec4_t * v2, f64 amt);
    emp limit_std_vec4_t  (std_vec4_t * v, f64 scalar);
    emp scale_std_vec4_t  (std_vec4_t * v, f64 scalar);
    emp normal_std_vec4_t (std_vec4_t * v);
    emp set_std_vec4_t_mag(std_vec4_t * v, f64 scalar);
    
    f64 get_std_vec4_t_mag         (std_vec4_t * vec);
    f64 get_dot_prod_std_vec4_t    (std_vec4_t * v1, std_vec4_t * v2);
    f64 get_dist_between_std_vec4_t(std_vec4_t * v1, std_vec4_t * v2); 

    // projects v1 on v2
    std_vec4_t project_on_std_vec4_t(std_vec4_t * v1, std_vec4_t * v2);

/*

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Small Macros
#define square(expression) expression * expression
#define distance_between_1d_points(c1, c2) c2 - c1
#define distance_between_2d_points(x1, y1, x2, y2) sqrt(square(distance_between_1d_points(x1, x2)) \
			    	                      + square(distance_between_1d_points(y1, y2)))
#define direction_between_points(x1, y1, x2, y2) atan2(distance_between_1d_points(y1, y2), \
						       distance_between_1d_points(x1, x2))
#define deg_to_rad(deg) deg * (M_PI / 180)
#define rad_to_deg(rad) rad * (180 / M_PI)

#define PI 3.14159265358979
#define TAU 6.283184
#define THREE_HALFS 1.5f

//////////////// Vectors
// Use pointers all the time..


float fast_inverse_sqrt(float number) {
    long i;
    float x2, y;

    x2 = number * 0.5f;
    y = number;
    i = * (long *) &y;
    i = 0x5f3759df - (i >> 1);
    y = * (float *) &i;
    y = y * (THREE_HALFS - (x2 * square(y)));

    return y;
    
}

float lerp_f(float start, float stop, float amt) {
    return start + (stop-start) * amt;
}

typedef struct {
    float x;
    float y;
} vec2;

void init_vec2(vec2 * vec, int x, int y) {
    vec -> x = x;
    vec -> y = y;
}

void add_vec2(vec2 * vec_one, vec2 * vec_two) {
    vec_one -> x = vec_two -> x + vec_one -> x;
    vec_one -> y = vec_two -> y + vec_one -> y;
}

void sub_vec2(vec2 * vec_one, vec2 * vec_two) {
    vec_one -> x = vec_two -> x - vec_one -> x;
    vec_one -> y = vec_two -> y - vec_one -> y;
}

double get_vec2_mag(vec2 * vec) {
    return (sqrt(vec -> x * vec -> x + vec -> y * vec -> y)); 
}

void normalize_vec2(vec2 * vec, double mag) {
    vec -> x = vec -> x / mag;
    vec -> y = vec -> y / mag;
}

void multiply_vec2_by_scalar(vec2 * vec, float scalar) {
    vec -> x = vec -> x * scalar;
    vec -> y = vec -> y * scalar;
}

void divide_vec2_by_scalar(vec2 * vec, float scalar) {
    vec -> x = vec -> x / scalar;
    vec -> y = vec -> y / scalar;
}

void set_vec2_mag(vec2 * vec, float scalar) {
    normalize_vec2(vec, get_vec2_mag(vec));
    multiply_vec2_by_scalar(vec, scalar);
}

float get_angle_of_vec2(vec2 * vec) {
    return atan2(vec -> y, vec -> x);
}

void rotate_vec2(vec2 * vec, float theta) {
    float temp = vec -> x;
    vec -> x = vec -> x * cos(theta) - vec -> y * sin(theta);
    vec -> y = temp * sin(theta) + vec -> y * cos(theta);
}

void lerp_vec2(vec2 * vec_one, vec2 * vec_two, float amt) {
    vec_one -> x = lerp_f(vec_one -> x, vec_two -> x, amt);
    vec_one -> y = lerp_f(vec_one -> y, vec_two -> y, amt);
}

float get_distance_between_two_vec2(vec2 * vec_one, vec2 * vec_two) {
    float dx = vec_one -> x - vec_two -> x;
    float dy = vec_one -> y - vec_two -> y;
    return sqrt(dx * dx + dy * dy);
}

float get_dot_product_vec2(vec2 * vec_one, vec2 * vec_two) {
    return vec_one -> x * vec_two -> x + vec_one -> y * vec_two -> y;
}

double get_angle_between_two_vec2(vec2 * v1, vec2 * v2) {
    if (v1 -> x == 0 && v1 -> y == 0) return 0.0f;
    if (v2 -> x == 0 && v2 -> y == 0) return 0.0f;

    double dot = v1 -> x * v2 -> x + v1 -> y * v2 -> y;
    double v1mag = get_vec2_mag(v1);
    double v2mag = get_vec2_mag(v2);
    double amt = dot / (v1mag * v2mag);

    if (amt <= -1) {
      return M_PI;
    } else if (amt >= 1) {
      return 0;
    }
    return acos(amt);
}


void limit_vec2(vec2 * vec, float scalar) {
    double len = vec -> x * vec -> x + vec -> y * vec -> y;
    double len_t = scalar * scalar;
    if (len > len_t) {
        double mag = get_vec2_mag(vec);
        normalize_vec2(vec, mag);
        multiply_vec2_by_scalar(vec, scalar);
    }     
}


typedef struct {
    float x;
    float y;
    float z;
} vec3;

void init_vec3(vec3 * vec, int x, int y, int z) {
    vec -> x = x;
    vec -> y = y;
    vec -> z = z;
}

void add_vec3(vec3 * vec_one, vec3 * vec_two) {
    vec_one -> x = vec_two -> x + vec_one -> x;
    vec_one -> y = vec_two -> y + vec_one -> y;
    vec_one -> z = vec_two -> z + vec_one -> z;
}

void sub_vec3(vec3 * vec_one, vec3 * vec_two) {
    vec_one -> x = vec_two -> x - vec_one -> x;
    vec_one -> y = vec_two -> y - vec_one -> y;
    vec_one -> z = vec_two -> z - vec_one -> z;
}

double get_vec3_mag(vec3 * vec) {
    return (sqrt(vec -> x * vec -> x + vec -> y * vec -> y + vec -> z * vec -> z)); 
}

void normalize_vec3(vec3 * vec, double mag) {
    vec -> x = vec -> x / mag;
    vec -> y = vec -> y / mag;
    vec -> z = vec -> z / mag;
}

void multiply_vec3_by_scalar(vec3 * vec, float scalar) {
    vec -> x = vec -> x * scalar;
    vec -> y = vec -> y * scalar;
    vec -> z = vec -> z * scalar;
}

void divide_vec3_by_scalar(vec3 * vec, float scalar) {
    vec -> x = vec -> x / scalar;
    vec -> y = vec -> y / scalar;
    vec -> z = vec -> z / scalar;
}

void set_vec3_mag(vec3 * vec, float scalar) {
    normalize_vec3(vec, get_vec3_mag(vec));
    multiply_vec3_by_scalar(vec, scalar);
}


void lerp_vec3(vec3 * vec_one, vec3 * vec_two, float amt) {
    vec_one -> x = lerp_f(vec_one -> x, vec_two -> x, amt);
    vec_one -> y = lerp_f(vec_one -> y, vec_two -> y, amt);
    vec_one -> z = lerp_f(vec_one -> z, vec_two -> z, amt);
}

float get_distance_between_two_vec3(vec3 * vec_one, vec3 * vec_two) {
    float dx = vec_one -> x - vec_two -> x;
    float dy = vec_one -> y - vec_two -> y;
    float dz = vec_one -> z - vec_two -> z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

float get_dot_product_vec3(vec3 * vec_one, vec3 * vec_two) {
    return vec_one -> x * vec_two -> x + vec_one -> y * vec_two -> y + vec_one -> z * vec_two -> z;
}

vec3 get_cross_product_of_vec3(vec3 * vec_one, vec3 * vec_two) {
     vec3 newVec = {
			.x = vec_one -> y * vec_two -> z - vec_one -> z * vec_two -> y,
			.y = vec_one -> z * vec_two -> x - vec_one -> z * vec_two -> z,
			.z = vec_one -> x * vec_two -> y - vec_one -> y * vec_two -> x
		    };

    return newVec;

}

void limit_vec3(vec3 * vec, float scalar) {
    double len = vec -> x * vec -> x + vec -> y * vec -> y + vec -> z * vec -> z;
    double len_t = scalar * scalar * scalar;
    if (len > len_t) {
        double mag = get_vec3_mag(vec);
        normalize_vec3(vec, mag);
        multiply_vec3_by_scalar(vec, scalar);
    }     
}

typedef struct {
    float x, y, z, w;
} vec4;


//////////////// Matrices


/// Quaternions

//////////////// Physics 

//////////////// Physics 

typedef struct {
    int x, y;
    float width, height;
} Rect2D;

#define checkRect(rect) rect.x = 0;\
				    rect.y = 0;\

void CheckRect(Rect2D * rect) {
    if (rect == NULL) {
	rect -> x = 0;
	rect -> y = 0;
    }
}

// Add vector conversion


*/

#endif
