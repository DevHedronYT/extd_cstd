
lib:
	cd build/output/ && gcc -c ../../src/linked_list.c -I../../include


lib_test:
	cd build/test_build/ && gcc ../../tests/test_ll.c -g ../output/linked_list.o -I../../include/

