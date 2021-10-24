CC = gcc
OUT = -o ./build/libc_std_lib.a 
FLAGS = -shared -g -O0

lib:
	$(CC) $(FLAGS) ./src/*.c -I ./include/ $(OUT) 
	



