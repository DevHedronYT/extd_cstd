#include <extd_cstd/lib.h>

i08 file_exists(char * path) {
    assert(path != NULL);
    FILE * f = fopen(path, "r");
    assert(f != NULL);
    assert(fclose(f) == 0);
    return 1;
}

// Maximum readable size is 2 GB
file_info_t txt_file_query(char * path) {
    assert(path != NULL);
    FILE * f = fopen(path, "r");
    assert(f != NULL);

    file_info_t file;
    file.path = path;

    assert(fseek(f, 0, SEEK_END) == 0);

    file.len = ftell(f);
    assert(file.len > -1);

    file.content = calloc(file.len + 1, sizeof(char));
    assert(file.content != NULL);
    
    rewind(f);
    
    assert(fread(file.content, sizeof(char), file.len, f) == file.len);
    file.content[file.len + 1] = '\0';
    
    assert(fclose(f) == 0);
    return file;
}

// It's not possible to write binary data, or more than 2GB, using write_file.
i08 txt_file_write(char * content, char * path, size_t len) { 
    assert(content != NULL && path != NULL && len > 0);
    FILE * f = fopen(path, "wb");
    assert(f != NULL);
    assert(fwrite(content, sizeof(char), len, f) == len);
    assert(fclose(f) == 0);
    return 1;
}


