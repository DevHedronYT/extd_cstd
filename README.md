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
### Dynamic List - ``dynamic_list.h``:
- ``struct std_dynamic_list_t_node_t``:
    - Struct contains, data which has been cast to ``void *`` and the type as a string

- ``struct std_dynamic_list_t``:
    - Struct contains, size of dynamic list, data in dynamic list cast to ``void *`` and the real size of the dynamic list

- ``init_std_dynamic_list_t_node_t(std_dynamic_list_t_node_t * node, void * data, const char * type);``:
    - Initializes list node, while nodes seems like overkill for an implementation of a dynamic list, this allows the dynamic list to consist of completely different data types and the node struct contains the type as well so that if the element you are looking for to remove, say has the same address as another element, BUT it does not have the same type, it will not remove that element. 

- ``std_dynamic_list_t_node_t * create_std_dynamic_list_t_node_t(void * data, const char * type);``: 
    - Allocates memory and returns a dynamic list node and this is for faster node creation
- ``void init_std_dynamic_list_t(std_dynamic_list_t * list);``:
    - Initializes a dynamic list and allocates memory for 1 node 

- ``void add_elem_to_std_dynamic_list_t(std_dynamic_list_t * list, std_dynamic_list_t_node_t * node);``:
    - Adds dynamic list node to end of list

- ``void remove_elem_from_std_dynamic_list_t_at(std_dynamic_list_t * list, int index);``:
    - Removes node from list at certain index

- ``void remove_elem_from_std_dynamic_list_t(std_dynamic_list_t * list, std_dynamic_list_t_node_t * node);``:
    - Removes node from list if the data of the node and its type exists in the list

- ``void * get_std_dynamic_list_t_node_t_data_value_at(std_dynamic_list_t * list, int index);``:
    - Gets the data which has been cast to ``void *`` at a certain index in the dynamic list

- ``void uninit_std_dynamic_list_t(std_dynamic_list_t * list);``:
    - Frees memory allocated for dynamic list

