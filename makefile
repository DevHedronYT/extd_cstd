
all:
	make lib
	make test 

lib:
	cd build/output/ && gcc -c ../../src/*.c -I../../include -Wall -O3

test: 
	cd build/test_build/ && gcc ../../tests/test_$(FILE).c -I../../include -g ../output/*.o -Wall -o $(FILE) -O3

clean:
	rm -rf build/output/*
	rm -rf build/test_build/*

