#ifndef _C_STD_STRING

    #define _C_STD_STRING
    
    #define str char *
   
    int    std_str_length     (const str str_one);
    int	   std_str_compare    (const str str_one, const str str_two);
    str    std_str_concat     (const str str_one, const str str_two);
    int    std_str_subchar    (str str_one, char letter);
    int    std_str_substring  (const str str_one, const str str_two);
    int    std_str_starts_with(const str str_one, const str str_two);
    int    std_str_ends_with  (str str_one, str str_two);
    str    std_str_reverse    (str str_one);
    str    std_str_split      (const str str_one, char c);

#endif 

