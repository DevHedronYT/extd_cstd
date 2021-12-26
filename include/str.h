#ifndef _STR_H_
    #define _STR_H_
    
    #include <types.h>  

    char * str_split      (const char * str_one, char c);
    i32    str_length     (const char * str_one);
    char * str_concat     (const char * str_one, const char * str_two);
    i32    str_compare    (const char * str_one, const char * str_two);
    char * str_reverse    (char * str_one);
    i32    str_subchar    (char * str_one, char letter);
    i32    str_ends_with  (char * str_one, char * str_two);
    i32    str_substring  (const char * str_one, const char * str_two);
    i32    str_starts_with(const char * str_one, const char * str_two);
    char * i32_to_str     (i32 num);
    i32    str_to_i32     (char * string);
    char * f64_to_str     (f64 num);

#endif 

