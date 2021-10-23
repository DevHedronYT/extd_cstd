#ifndef _C_STD_FILE

    #define _C_STD_FILE

    #include <types.h>

    typedef struct {
        str_t content;
        str_t path;
        u32_t len;
    } file_t;

    i08_t  file_exists(str_t path);
    file_t load_file(str_t path);
    i08_t  write_file(str_t content, str_t path);

#endif
