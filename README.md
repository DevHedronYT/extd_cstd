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

### File - ``file.h``:

- ``char * std_load_text_file(const char * name);``:
    - Loads text file

### Hash Table - ``hash_table.h``:

- ``struct std_hash_table_t_node_t``:
    - This node struct contains data of the node cast to ``void *`` and the key in string form and the hash value. 

- ``struct std_hash_table_t``:
    - This hash table struct contains data as nodes and the size

- ``int hash_hash_table_t_node_t(const char * key)``: 
    - This function returns a value in int, it generates the value depending on the ascii character value of that letter

- ``void init_std_hash_table_t_node_t(std_hash_table_t_node_t * node, void * data, char * key)``:
    - This function initializes the node just like the dynamic list node function

- ``std_hash_table_t_node_t * create_std_hash_table_t_node_t(void * data, char * key);``:
    - This function creates a hash table node

- ``void init_std_hash_table_t(std_hash_table_t * table);``:
    - This will initialize a hash table, and allocates 1000 ``std_hash_table_t_node_t`` nodes

- ``void add_pair_to_std_hash_table_t(std_hash_table_t * table, std_hash_table_t_node_t * node);``:
    - This adds a `std_hash_table_t_node_t` node, to the hash table

- ``void remove_elem_from_std_hash_table_t_at(std_hash_table_t * table, const char * key)``:
    - This will remove an element from the hash table if it has the same key 

- ``void * get_std_hash_table_t_node_t_data_value_at(std_hash_table_t * table, const char * key);``:
    - Returns the value which has been cast to ``void *`` and has the same key

- ``void uninit_std_hash_table_t(std_hash_table_t * table);``:
    - Frees memory allocated for hash table

