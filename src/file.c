#include <stdio.h>
#include <stdlib.h>
#include <file.h>

file_t le_load_file(str_t path) {
    FILE * f = fopen(path, "r");
        
    file_t file_final;

    if (f) {
        fseek(f, 0, SEEK_END);
        file_final.len = ftell(f);
        file_final.content = (str_t) malloc(file_final.len * sizeof(str_t));
        rewind(f);
        fread(file_final.content, sizeof(chr_t), file_final.len, f);
        file_final.content[file_final.len] = '\0';
        fclose(f);

        file_final.path = path;

        return file_final;
    }

    else {
        return (file_t){"NULL", path, -1};
    }
}




