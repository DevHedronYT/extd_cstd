# c_std_lib
Implementations Of DSA And More

## Building
Build the library using Make: 
```sh
mkdir build
mkdir build/output
mkdir build/test_build
make lib
```
This will output .o files stored in build/output, and you can compile the test you want, using:
```sh
mkdir build/test_build
make test FILE=NAME_OF_FILE 
build/test_build/name
```
> FILE variable should only contain name like ll or queue or stack and no test_ or .c extension

## DSA Time Complexities
Coming Soon
