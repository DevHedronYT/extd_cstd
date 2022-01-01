#ifndef FILE_H
    #define FILE_H 
    #include "./types.h"

    typedef struct {
        char * content;
        char * path;
        u32 len;
    } file_info_t;

    i08         file_exists(char * path);
    // Maximum size you can read is 2gb
    file_info_t txt_file_query (char * path);
    i08         txt_file_write (char * content, char * path, size_t len); 

    // Implement writing binary data

#endif
