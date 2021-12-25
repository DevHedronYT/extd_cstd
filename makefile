CC = gcc
OUT = -o ./build/libcstd.a 
FLAGS = -shared -g -O0

lib:
	$(CC) $(FLAGS) ./src/*.c -I ./include/ $(OUT) 
	
test:
	$(CC) -Lbuild -lcstd -I ./include/ -std=c99 tests/$(TEST)_test.c -o build/$(TEST) 	


