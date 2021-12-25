#include <types.h>
#include <util.h>
#include <file.h>

i32_t main() {
	str_t string = "hello, world, testing write to file";
	str_t file_name = "./file.test";
	if (write_file(string, file_name)) {
		print("Successfully wrote to: %s\n", file_name);
	}
	else {
		print("Failed to write to: %s\n", file_name);	
	}

	str_t file_n = "../tests/file_test.c";
	file_t file_r = load_file(file_n);
	print("Loaded: %s\n", file_n);
	print("%s\n", file_r.content);
}
