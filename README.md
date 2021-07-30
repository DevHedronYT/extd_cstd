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

## Docs
- Dynamic List - ``dynamic_list.h``:
    - ``init_std_dynamic_list_t_node_t(std_dynamic_list_t_node_t * node, void * data, const char * type);``:
	- Initializes list node, while nodes seems like overkill for an implementation of a dynamic list, this allows the dynamic list to consist of completely different data types and the node struct contains the type as well so that if the element you are looking for to remove, say has the same address as another element, BUT it does not have the same type, it will not remove that element. 

    - ``std_dynamic_list_t_node_t * create_std_dynamic_list_t_node_t(void * data, const char * type);``: 
	- Allocates memory and returns a dynamic list node and this is for faster node creation

