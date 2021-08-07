#include <stdio.h>
#include <stdlib.h>
#include <file.h>

str load_text_file(const str name) {
    str buffer = 0;
    i32 length;
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


