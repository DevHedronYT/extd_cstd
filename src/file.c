#include <file.h>
#include <stdlib.h>
#include <str.h>

i08 file_exists(char * path) {
    FILE * f = fopen(path, "r");
    if (f) {
        fclose(f);
        return 1;
    }

    return 0;
}

file_t load_file(char * path) {
    FILE * f = fopen(path, "r");
    file_t file;

    file.file = f;

    if (f) {
        fseek(f, 0, SEEK_END);
        file.len = ftell(f);
        file.content = calloc(file.len, sizeof(char *));
        rewind(f);
        fread(file.content, sizeof(char), file.len, f);
        file.content[file.len] = '\0';
        fclose(f);

        file.path = path;

        return file;
    }

    else {
        return (file_t){NULL, path, NULL, -1};
    }
}

i08 write_file(char * content, char * path) { 
    FILE * f = fopen(path, "wb");
    
    if (!f) { return 0;  }
    i32 len = str_length(content);
    fwrite(content, sizeof(char), len, f);
    fclose(f);
    return 1;
}


