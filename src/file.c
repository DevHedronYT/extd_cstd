#include <stdio.h>
#include <stdlib.h>

char * load_text_file(const char * name) {
    char * buffer = 0;
    long length;
    FILE * f = fopen(name, "rb");

    if (f) {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc(length);
        
        if (buffer){
            fread(buffer, 1, length, f);
        }
        
        fclose(f);

    }

    return buffer;
}


