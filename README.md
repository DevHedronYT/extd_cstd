# extd_cstd 
- This is a multi-platform simple C library written using C99 meant to build on top of the C 
library or improve it, including implementations of:
    - [File I/O](./include/extd_cstd/file.h)
    - [List](./include/extd_cstd/list.h)
    - [Hash Table](./include/extd_cstd/ht.h)
    - [Custom Log Functions With ANSI Colors & Time](./include/extd_cstd/log.h)
    - [Maths Library [OpenGL Compliant]](./include/extd_cstd/maths.h)
    - [Profiler](./include/extd_cstd/prof.h)
    - [String Functions](./include/extd_cstd/str.h)

## Building
- Build the library using Make: 
```sh
mkdir build
make 
```
- This will output a file called `libextd_cstd.a`
which you can use to run the programs and ..etc..
I could maybe make this whole library header only 
though

- The tests are easy to build as well. Right now there are
tests for all of the files but multiple are done within a 
single file, for example, [ht_test.c](./tests/ht_test.c) 
does a profiler test, string test, hash table test, 
math library test, logging test and custom types set in
a single file. To build the tests, you first have to build
the library as mentioned above and then:
```sh
make test TEST=test_name 
build/test_name
```
- test_name in this case would either be ht, list, file or log.

## Documentation
- None as of now 
