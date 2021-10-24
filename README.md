# c_std_lib
This is a simple C standard library written using C99, lib includes implementations of:
    - [Custom Types](./include/types.h)
    - [File I/O](./include/file.h)
    - [List](./include/list.h)
    - [Hash Table](./include/ht.h)
    - [Custom Print Functions With ANSI Colors & Time](./include/util.h)
    - [Maths Engine [OpenGL Compliant]](./include/me.h)
    - [Profiler](./include/prof.h)
    - [String Funtions](./include/str.h)

## Building
Build the library using Make: 
```sh
mkdir build
make 
```
This will output a file called libc_std_lib.a
which you can use to run the programs and ..etc..
I could maybe make this whole library header only 
though

## Docs
### [Custom Types](./include/types.h)

- ``#define i08_t  int8_t``:
    - 8-bit integer

- ``#define i16_t  int16_t``:
    - 16-bit integer

- ``#define i32_t int32_t``:
    - 32-bit integer

- ``#define i64_t  int64_t``:
    - 64-bit integer

- ``#define f32_t float``:
    - 32-bit float

- ``#define f64_t double``:
    - 64-bit float

- ``#define u08_t uint8_t``:
    - 8-bit unsigned integer

- ``#define u16_t uint16_t``:
    - 16-bit unsigned integer

- ``#define u32_t uint32_t``:
    - 32-bit unsigned integer

- ``#define u64_t uint64_t``:
    - 64-bit unsigned integer

- ``#define emp_t void``:
    - Void

- ``#define ret_t void *``:
    - Void Pointer

- ``#define str_t char *``:
    - String

- ``#define chr_t char``:
    - Char

### [File I/O](./include/file.h)
```c
    typedef struct {
        str_t content;
        str_t path;
        u32_t len;
    } file_t;
```
- This is a file struct which is used for the reading of files

```c
    i08_t  file_exists(str_t path);
    file_t load_file(str_t path);
    i08_t  write_file(str_t content, str_t path);
```
- These are the functions that this header includes. Not a lot and quite simple

- The `file_exists` functions returns 0 if there is no file found otherwise it returns a 1. All you 
have to pass to it is the path

- The `load_file` function loads a file and returns a `file_t` struct, it takes in the path
as well. 

- The `write_file` function writes to a file and returns `1` if it was successful

### [List](./include/list.h)
```c
    typedef struct {
        ret_t * data;
        u32_t   len;
        u32_t   idx;
    } list_t;
``` 
- This is the list struct which is used for creating and using lists

```c
    list_t create_list(u32_t capacity);
    emp_t __push_to_list(list_t * list, ret_t data);
    emp_t remove_from_list_at(list_t * list, u32_t idx);
    emp_t __remove_from_list(list_t * list, ret_t data,
                          i08_t (* compare_func)(ret_t x, ret_t y));
    i32_t __get_in_list_t(list_t * list, ret_t data, 
                          i08_t (* compare_func)(ret_t x, ret_t y));
    emp_t free_list(list_t * list);

    #define push_to_list(list, data)
    #define get_at_list_t(list, index, type)
    #define get_data(list, data, func, type)
    #define remove_from_list(list, data, compare_func)
```
- These are all the functions used for the list data structure and the API
is much better than the previous one in my honest opinion.  

##### NOTE: I won't be explaining the functions that start with `__` as they are to be used only by the API

- The `create_list` function creates a list by taking an argument of `capacity` and allocates that much space
and it returns a list struct
- The `remove_from_list_at` removes from a given list pointer at a given index
- The `free_list` function frees the list by freeing all the allocated space

- The macros:
    - The `push_to_list` macro takes in a pointer to list along with data of any type other than void *
    - The `get_at_list_t` macro takes in a list and index and type and returns the data at that
    index casted to the type
    - The `get_data` macro does something very similar to `get_at_list_t`, it takes in a list (no pointer),
    the data you want to look for, the compare function, which if you want can be null unless
    you are using custom types in which case a custom compare function like this would work:
        ```c
            i08_t compare_func(ret_t data_one, ret_t data_two) { // Comparison  };
        ```
    After the compare function, it takes in a type as well and then returns the data casted
    to that type
    - The `remove_from_list` macro takes in the list pointer and the data you want to remove
    and a compare function which can be NULL but as I said above, if you are using custom types,
    make a custom compare function.

### [Hash Table](./include/ht.h)
```c
    typedef struct {
        const str_t id;
        u64_t       hash;
        ret_t       val;
    } ht_item_t;

    typedef struct {
        ht_item_t * data;
        u32_t       len;
        u32_t       capacity;
    } ht_t; 
```
- These are the structs used for the hash table implementation, nothing complicated,
also much simpler than the previous API

```c
    ht_t create_ht(u32_t capacity);
    u64_t hash_id(const str_t id);
    emp_t increase_ht_capacity(ht_t * ht, u32_t capacity);
    emp_t __insert_to_ht(ht_t * ht, const str_t id, ret_t data);
    ret_t __get_from_ht(ht_t * ht, const str_t id);
    u32_t rm_from_ht(ht_t * ht, const str_t id);
    emp_t rm_ht(ht_t * ht);

    #define insert_to_ht(ht, id, data)
    #define get_from_ht(ht, id, type) 
```
- All the functions for my hash table API implementation

##### NOTE: I won't be explaining the functions that start with `__` as they are to be used only by the API


- The `create_ht` works similar to the list function and takes in a `capacity` argument
and allocates that much space and returns it

- The `hash_id` function takes in a `const str_t` and hashes it using the algorithm used by
Ben Hoyt in his hash table tutorials as well and it returns a 64-bit unsigned integer

- Then there is the `increase_ht_capacity` which takes in a pointer to the hash table and 
then the new capacity as a 32-bit unsigned int and then reallocates that much space

- Then there is the `rm_from_ht` function which takes in the pointer to the hash table
and the ID of the value that you want to delete and it returns the index of the deleted
element.

- Finally there is the `rm_ht` function which frees the memory allocated by the hash table

- The macros: 
    - The `insert_to_ht` macro takes in a hash table pointer and the id and the data of any type other than void * 
    - The `get_from_ht` macro takes in a hash table pointer, the id and the type of the data you want to retrieve
    which returns the data casted to the type 


### [Custom Print Functions With ANSI Colors & Time](./include/util.h)

- The functions in this header are also self-explanatory although I have left comments and the colors in whic
each function prints in
```c
    // Sets output background color
    #define set_output_bg_color(x) 

    // Prints arguments normally
    emp_t print(const str_t fmt, ...);

    // Prints arguments with new line at end
    emp_t print_n(const str_t fmt, ...);

    // Prints arguments with time at start
    emp_t print_t(const str_t fmt, ...);

    // Prints arguments with time at start in the green color
    emp_t print_i(const str_t fmt, ...); // Info

    // Prints arguments with time at start in the red color
    emp_t print_e(const str_t fmt, ...); // Error

    // Prints arguments with time at start in the yellow color
    emp_t print_w(const str_t fmt, ...); // Warning


    // Prints arguments with time at start in the red color in bold
    emp_t print_fe(const str_t fmt, ...); // Fatal Error


    // Prints arguments with time at start in the blue color underlined
    emp_t print_s(const str_t fmt, ...);  // Important Message
```


### [Maths Engine [OpenGL Compliant]](./include/me.h)
```c

typedef struct {
    f64_t x;
    f64_t y;
} v2_t;

typedef struct {
    f64_t x;
    f64_t y;
    f64_t z;
} v3_t;

typedef struct {
    f64_t x;
    f64_t y;
    f64_t z;
    f64_t w;
} v4_t;

typedef struct {
    f32_t elems[4][4];
} m4x4_t;

```
- These are the structs used for the maths engine, starts with a vector 2 or `v2_t` and ends with a 4x4 matrix or `m4x4_t` (The matrix is layed out in the way OpenGL expects)

```c
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

    m4x4_t mk_m4x4(f32_t m00, f32_t m01, f32_t m02, f32_t m03,
                   f32_t m04, f32_t m05, f32_t m06, f32_t m07,
                   f32_t m08, f32_t m09, f32_t m10, f32_t m11,
                   f32_t m12, f32_t m13, f32_t m14, f32_t m15);

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

```
- The code has been written in the most easiest way to understand and if you are making an OpenGL program
then definitely use this and tell me how it goes


### [Profiler](./include/prof.h)
```c
    typedef struct {
        str_t name;
        f64_t elapsed;
        str_t elapsed_string;
    } prof_t;
```
- The profiler uses this simple struct with a name for the function, elapsed time and the elapsed time 
converted to a string

```c
    emp_t start_profiling(prof_t * profiler, str_t name); // Takes in a pointer to the profiler and name of function you are profiling
    emp_t end_profiling  (prof_t * profiler); // Takes in pointer to the profiler that was being used 
```
- Literally the most simple functions, you can figure out how to use them

### [String Funtions](./include/str.h)

- This is a very self-explanatory implementation of most of the string functions so I won't
really be explaining everything althought I have left comments
```c
    // Splits a string at a char c
    str_t str_split      (const str_t str_one, chr_t c);

    // Returns length of string
    i32_t str_length     (const str_t str_one);

    // Concatenates a string
    str_t str_concat     (const str_t str_one, const str_t str_two);

    // Compares 2 strings
    i32_t str_compare    (const str_t str_one, const str_t str_two);

    // Reverses a string 
    str_t str_reverse    (str_t str_one);

    // Checks if a letter exists in the string
    i32_t str_subchar    (str_t str_one, chr_t letter);

    // Checks if string ends with a sub-string
    i32_t str_ends_with  (str_t str_one, str_t str_two);

    // Check if there is a sub-string within a string 
    i32_t str_substring  (const str_t str_one, const str_t str_two);

    // Checks if the string starts with a string
    i32_t str_starts_with(const str_t str_one, const str_t str_two);

    // Converts a 32-bit int to a string
    str_t i32_to_str     (i32_t num);

    // Converts a string to a 32-bit int
    i32_t str_to_i32     (str_t string);

    // Converts a 64-bit float to a string
    str_t f64_to_str     (f64_t num);
```

