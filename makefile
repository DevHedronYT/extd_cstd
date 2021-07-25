
all:
	make lib
	make test_file 

lib:
	cd build/output/ && gcc -c ../../src/*.c -I../../include -Wall

test: 
	cd build/test_build/ && gcc ../../tests/test_$(FILE).c -I../../include -g ../output/*.o -Wall -o $(FILE)

clean:
	rm -rf build/output/*
	rm -rf build/test_build/*

