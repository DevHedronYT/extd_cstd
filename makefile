
lib:
	cd build/output/ && gcc -c ../../src/*.c -I../../include -Wall

del:
	rm -rf build/output/*
	rm -rf build/test_build/*

