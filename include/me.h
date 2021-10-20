#ifndef _C_STD_ME

    #define _C_STD_ME
    
    #include <types.h>
   
    /// ??? = help needed
    // Just a little context, f64 is a 64-bit float, aka double while f32 which you barely see is the normal form of floats in C

    #define pi 3.14159265358979
    #define deg_to_rad(deg) deg * (std_pi / 180)
    #define rad_to_deg(rad) rad * (180 / std_pi)
    #define sqr(e) e * e
    #define dist1D(c1, c2) c2 - c1

   
    f64_t dist2D  (f64_t x1, f64_t y1, f64_t x2, f64_t y2);
    f64_t dir2D   (f64_t x1, f64_t y1, f64_t x2, f64_t y2);
    f64_t inv_sqrt(f64_t num);
    f64_t lerp_f  (f64_t start, f64_t stop, f64_t amt);
   
    typedef struct {
        f64_t x;
        f64_t y;
    } v2_t;

    #define mk_v2_zero() (v2_t) { .x = 0.0f, .y = 0.0f };
    #define mk_v2_one () (v2_t) { .x = 1.0f, .y = 1.0f };
    #define mk_v2(_x, _y) (v2_t) { .x = _x, .y = _y };

    emp_t add_v2    (v2_t * v1, v2_t * v2);
    emp_t sub_v2    (v2_t * v1, v2_t * v2);
    emp_t lerp_v2   (v2_t * v1, v2_t * v2, f64_t amt);
    emp_t limit_v2  (v2_t * v, f64_t scalar);
    emp_t scale_v2  (v2_t * v, f64_t scalar);
    emp_t normal_v2 (v2_t * v);
    emp_t rotate_v2 (v2_t * v, f64_t theta);
    emp_t set_v2_mag(v2_t * v, f64_t scalar);

    f64_t v2_mag         (v2_t * v);
    f64_t v2_angle       (v2_t * v);
    f64_t v2_dot_prod    (v2_t * v1, v2_t * v2);
    f64_t dist_between_v2(v2_t * v1, v2_t * v2);
    f64_t angle_between_v2(v2_t * v1, v2_t * v2);

    v2_t v2_projection(v2_t * v1, v2_t * v2);

    typedef struct {
        f64_t x;
        f64_t y;
        f64_t z;
    } v3_t;

    #define mk_v3_zero() (v3_t) { .x = 0.0f, .y = 0.0f, .z = 0.0f };
    #define mk_v3_one () (v3_t) { .x = 1.0f, .y = 1.0f, .z = 1.0f };
    #define mk_v3(_x, _y, _z) (v3_t) { .x = _x, .y = _y, .z = _z };

    emp_t add_v3    (v3_t * v1, v3_t * v2);
    emp_t sub_v3    (v3_t * v1, v3_t * v2);
    emp_t lerp_v3   (v3_t * v1, v3_t * v2, f64_t amt);
    emp_t limit_v3  (v3_t * v, f64_t scalar);
    emp_t scale_v3  (v3_t * v, f64_t scalar);
    emp_t normal_v3 (v3_t * v);
    emp_t set_v3_mag(v3_t * v, f64_t scalar);
    
    f64_t v3_mag         (v3_t * v);
    f64_t v3_dot_prod    (v3_t * v1, v3_t * v2);
    f64_t dist_between_v3(v3_t * v1, v3_t * v2); 
    v3_t  v3_cross_prod  (v3_t * v1, v3_t * v2);
    // projects v1 on v2
    v3_t v3_projection   (v3_t * v1, v3_t * v2);

    typedef struct {
        f64_t x;
        f64_t y;
        f64_t z;
        f64_t w;
    } v4_t; // The size of a vec4 will be around 8 * 4 = 32 bytes, I am contemplating now whether I should use f64 or not

    #define mk_v4_zero() (v4_t) { .x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f };
    #define mk_v4_one () (v4_t){ .x = 1.0f, .y = 1.0f, .z = 1.0f, .w = 1.0f };
    #define mk_v4(x, y, z, w) (v4_t) { .x = x, .y = y, .z = z, .w = w };

    emp_t add_v4    (v4_t * v1, v4_t * v2);
    emp_t sub_v4    (v4_t * v1, v4_t * v2);
    emp_t lerp_v4   (v4_t * v1, v4_t * v2, f64_t amt);
    emp_t limit_v4  (v4_t * v, f64_t scalar);
    emp_t scale_v4  (v4_t * v, f64_t scalar);
    emp_t normal_v4 (v4_t * v);
    emp_t set_v4_mag(v4_t * v, f64_t scalar);
    
    f64_t v4_mag         (v4_t * vec);
    f64_t v4_dot_prod    (v4_t * v1, v4_t * v2);
    f64_t dist_between_v4(v4_t * v1, v4_t * v2); 

    // projects v1 on v2
    v4_t v4_projection(v4_t * v1, v4_t * v2);


#endif
