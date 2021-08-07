#ifndef _C_STD_STRING

    #define _C_STD_STRING
    
    #include <types.h>  

    str std_str_split      (const str str_one, chr c);
    i32 std_str_length     (const str str_one);
    str std_str_concat     (const str str_one, const str str_two);
    i32 std_str_compare    (const str str_one, const str str_two);
    str std_str_reverse    (str str_one);
    i32 std_str_subchar    (str str_one, chr letter);
    i32 std_str_ends_with  (str str_one, str str_two);
    i32 std_str_substring  (const str str_one, const str str_two);
    i32 std_str_starts_with(const str str_one, const str str_two);
    str std_i32_to_str     (i32 num);
    i32 std_str_to_i32     (str string);

#endif 

