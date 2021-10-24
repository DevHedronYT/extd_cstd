#ifndef _C_STD_ME

    #define _C_STD_ME
    
    #include <types.h>
   
    #define pi 3.14159265358979
    #define deg_to_rad(deg) deg * (pi / 180)
    #define rad_to_deg(rad) rad * (180 / pi)
    #define sqr(e) e * e
    #define dist1D(c1, c2) c2 - c1
   
    f64_t dist2D  (f64_t x1, f64_t y1, f64_t x2, f64_t y2);
    f64_t dir2D   (f64_t x1, f64_t y1, f64_t x2, f64_t y2);
    f64_t inv_sqrt(f64_t num);
    f64_t ilerp   (f64_t start, f64_t stop, f64_t amt);
   
    i64_t randnum_gen(i64_t lower, i64_t upper);

    // Note projection functions 
    // project v1 onto v2

    typedef struct {
        f64_t x;
        f64_t y;
    } v2_t;

    #define mk_v2_zero() (v2_t) { .x = 0.0f, .y = 0.0f }
    #define mk_v2_one () (v2_t) { .x = 1.0f, .y = 1.0f }
    #define mk_v2(_x, _y) (v2_t) { _x, _y }

    emp_t add_v2    (v2_t * v1, v2_t * v2);
    emp_t sub_v2    (v2_t * v1, v2_t * v2);
    emp_t lerp_v2   (v2_t * v1, v2_t * v2, f64_t amt);
    emp_t limit_v2  (v2_t * v, f64_t scalar);
    emp_t scale_v2  (v2_t * v, f64_t scalar);
    emp_t normal_v2 (v2_t * v);
    emp_t rotate_v2 (v2_t * v, f64_t theta);
    emp_t set_v2_mag(v2_t * v, f64_t scalar);
    emp_t negate_v2 (v2_t * v);

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

    #define mk_v3_zero() (v3_t) { .x = 0.0f, .y = 0.0f, .z = 0.0f }
    #define mk_v3_one () (v3_t) { .x = 1.0f, .y = 1.0f, .z = 1.0f }
    #define mk_v3(_x, _y, _z) (v3_t) { _x, _y, _z }

    emp_t add_v3    (v3_t * v1, v3_t * v2);
    emp_t sub_v3    (v3_t * v1, v3_t * v2);
    emp_t lerp_v3   (v3_t * v1, v3_t * v2, f64_t amt);
    emp_t limit_v3  (v3_t * v, f64_t scalar);
    emp_t scale_v3  (v3_t * v, f64_t scalar);
    emp_t normal_v3 (v3_t * v);
    emp_t set_v3_mag(v3_t * v, f64_t scalar);
    emp_t negate_v3 (v3_t * v);
    
    f64_t v3_mag         (v3_t * v);
    f64_t v3_dot_prod    (v3_t * v1, v3_t * v2);
    f64_t dist_between_v3(v3_t * v1, v3_t * v2); 
    v3_t  v3_cross_prod  (v3_t * v1, v3_t * v2);
    v3_t  v3_projection  (v3_t * v1, v3_t * v2);
    f64_t angle_between_v3(v3_t * v1, v3_t * v2);


    typedef struct {
        f64_t x;
        f64_t y;
        f64_t z;
        f64_t w;
    } v4_t;

    #define mk_v4_zero() (v4_t) { .x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f }
    #define mk_v4_one () (v4_t){ .x = 1.0f, .y = 1.0f, .z = 1.0f, .w = 1.0f }
    #define mk_v4(_x, _y, _z, _w) (v4_t) { _x, _y, _z, _w }

    emp_t add_v4    (v4_t * v1, v4_t * v2);
    emp_t sub_v4    (v4_t * v1, v4_t * v2);
    emp_t lerp_v4   (v4_t * v1, v4_t * v2, f64_t amt);
    emp_t limit_v4  (v4_t * v, f64_t scalar);
    emp_t scale_v4  (v4_t * v, f64_t scalar);
    emp_t normal_v4 (v4_t * v);
    emp_t set_v4_mag(v4_t * v, f64_t scalar);
    emp_t negate_v4 (v4_t * v);
    
    f64_t v4_mag         (v4_t * vec);
    f64_t v4_dot_prod    (v4_t * v1, v4_t * v2);
    f64_t dist_between_v4(v4_t * v1, v4_t * v2); 

    v4_t v4_projection(v4_t * v1, v4_t * v2);

    v3_t v2_to_v3(const v2_t v);
    v4_t v3_to_v4(const v3_t v);
    v3_t v4_to_v3(const v4_t v);
    v2_t v3_to_v2(const v3_t v);

    typedef struct {
        f32_t elems[4][4];
    } m4x4_t;

    m4x4_t mk_m4x4(f32_t m00, f32_t m01, f32_t m02, f32_t m03,
                   f32_t m04, f32_t m05, f32_t m06, f32_t m07,
                   f32_t m08, f32_t m09, f32_t m10, f32_t m11,
                   f32_t m12, f32_t m13, f32_t m14, f32_t m15);
    // Some of the code has been took from
    // https://github.com/MrFrenik/gunslinger/blob/v0.02-alpha/include/math/gs_math.h
    // https://github.com/arkanis/single-header-file-c-libs/blob/master/math_3d.h
    // learnopengl.com/Getting-started/Transformations
    m4x4_t zero_m4x4();
    m4x4_t identity_m4x4();
    m4x4_t diag_m4x4(f64_t val);

    m4x4_t scale_m4x4_by_v3(m4x4_t mat, const v3_t vector);
    emp_t m4x4_add(m4x4_t * m1, m4x4_t * m2); 
    // Subtracts m1 from m2
    emp_t m4x4_sub(m4x4_t * m1, m4x4_t * m2); 
    m4x4_t m4x4_mult(m4x4_t m1, m4x4_t m2); 
    v4_t m4x4_mult_v4(m4x4_t m, v4_t v);
    v3_t m4x4_mult_v3(m4x4_t m, v3_t v);
    m4x4_t scale_m4x4_by_v3(m4x4_t mat, const v3_t vector);
    m4x4_t m4x4_rotate(f32_t degrees, v3_t axis);
    m4x4_t translate_m4x4(m4x4_t mat, const v3_t vector);
    m4x4_t mk_ortho_projection_m4x4(f32_t l, f32_t r, f32_t b, 
                                    f32_t t, f32_t n, f32_t f);
    
    m4x4_t mk_perspective_projection_m4x4(f32_t fov, f32_t asp_ratio, f32_t n, f32_t f);
    m4x4_t m4x4_mult_n(u32_t m4x4_count, ...);
    m4x4_t m4x4_lookat(v3_t pos, v3_t target, v3_t up);

    // Add:
    //  m3x3_t 
        //  lookat
    //  quternions
        //  
    // objects
    // rays



#endif
