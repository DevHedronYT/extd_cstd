#include <extd_cstd/lib.h>

i32 main() {
	char * string = "hello, world, testing write to file\0";
	char * file_name = "./file.test";
	if (txt_file_write(string, file_name, strlen(string))) {
		printf("Successfully wrote to: %s\n", file_name);
	}
	else {
		printf("Failed to write to: %s\n", file_name);	
	}

	char * file_n = "../tests/file_test.c";
	file_info_t file_r = txt_file_query(file_n);
	printf("Loaded: %s\n", file_n);
	printf("%s\n\n\n\n", file_r.content);
	printf("%d", file_r.len);
}
