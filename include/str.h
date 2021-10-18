#ifndef _STRING_H
    #define _STRING_H
    
    #include <types.h>  

    str_t str_split      (const str_t str_one, chr_t c);
    i32_t str_length     (const str_t str_one);
    str_t str_concat     (const str_t str_one, const str_t str_two);
    i32_t str_compare    (const str_t str_one, const str_t str_two);
    str_t str_reverse    (str_t str_one);
    i32_t str_subchar    (str_t str_one, chr_t letter);
    i32_t str_ends_with  (str_t str_one, str_t str_two);
    i32_t str_substring  (const str_t str_one, const str_t str_two);
    i32_t str_starts_with(const str_t str_one, const str_t str_two);
    str_t i32_to_str     (i32_t num);
    i32_t str_to_i32     (str_t string);
    str_t f64_to_str     (f64_t num);

#endif 

