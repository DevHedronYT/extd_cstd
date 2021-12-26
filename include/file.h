#ifndef _FILE_H_ 
    #define _FILE_H_ 
    #include <types.h>
    #include <stdio.h>

    typedef struct {
        char * content;
        char * path;
        FILE * file;
        u32 len;
    } file_t;

    i08  file_exists(char * path);
    file_t load_file(char * path);
    i08  write_file(char * content, char * path);

#endif
