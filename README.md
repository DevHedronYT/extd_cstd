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

### Linked List - ``linked_list.h``:
- ``struct std_ll_t_node_t``:
    - This is another node struct and this contains the data cast to ``void *`` and a pointer to the next node, the node also contains a string which contains the type just like a dynamic list node

- ``struct std_ll_t``:
    - This struct contains a pointer to the head of the linked list, and the last node of the linked list. It also contains the size of the linked list

- ``void init_std_ll_t_node_t(std_ll_t_node_t * node, void * data, std_ll_t_node_t * next, const char * type);``:
    - This function initializes a node just like the previous functions

- ``std_ll_t_node_t * create_std_ll_t_node_t(void * data, std_ll_t_node_t * next, const char * type);``:
    - This will create and return a linked list node

- ``void init_std_ll_t(std_ll_t * ll);``:
    - This will initialize a linked list

- ``int std_ll_t_insert_at_beginning(std_ll_t * ll, std_ll_t_node_t * data);``:
    - This inserts a ``std_ll_t_node_t`` node at the beginning of the linked list and returns status

- ``int std_ll_t_insert_at_end(std_ll_t * ll, std_ll_t_node_t * data);``:
    - This inserts a ``std_ll_t_node_t`` node at the end of the linked list and returns status

- ``int std_ll_t_remove(std_ll_t * ll, std_ll_t_node_t * remove_node);``:
    - This removes a `std_ll_t_node_t` node if it has the same type and data as the one supplied to the function

### Queue - ``queue.h``:

- ``struct std_queue_t_node_t``:
    - Another node structure for queues, contains data & pointer to next node

- ``struct std_queue_t``:
    - Structure for queue, contains the last node and the size of the queue

- ``void init_std_queue_t_node_t(std_queue_t_node_t * node, void * data, std_queue_t_node_t * next);``:
    - This function initializes a node for the queue and it takes in the address of the node you want to assign to and then takes in the data cast to ``void *`` and the pointer to the next node which can also be ``NULL``

- ``std_queue_t_node_t * create_std_queue_t_node_t(void * data, std_queue_t_node_t * next);``:
    - This function returns a pointer to a ``std_queue_t_node_t`` and this function is for fast node creation and it creates the node through dynamic memory allocation using ``malloc`` as do the other ``create_std_***_t_node_t`` functions

- ``void init_std_queue_t(std_queue_t * queue);``:
    - This function takes in a pointer to a ``std_queue_t`` and then initializes its values, ``m_end`` which is a pointer to a ``std_queue_t_node_t`` and ``m_size`` which is an ``int`` to NULL (the ``int`` is intialized to ``0``)

- ``std_queue_t_node_t peek_std_queue_t(std_queue_t * queue);``:
    - This function returns a ``std_queue_t_node_t``, it returns the node at the end of the queue

- ``void add_to_std_queue_t(std_queue_t * queue, std_queue_t_node_t * node);``:
    - This adds a node to the end of the queue

- ``int pop_from_std_queue_t(std_queue_t * queue);``:
    - Removes the node at the end of the queue and the node the end node was pointing to, becomes the end node

### Stack - ``stack.h``:

- ``struct std_stack_t_node_t``:
    - This node struct contains the data cast to ``void *`` and a pointer to another ``std_stack_t_node_t``

- ``struct std_stack_t``:
    - This stack struct contains the a pointer to the topmost ``std_stack_t_node_t`` node and the size of the stack

- ``void init_std_stack_t_node_t(std_stack_t_node_t * node, void * data, std_stack_t_node_t * next);``:
    - This function initializes a stack node by taking in a pointer to it, then the data cast to ``void *`` and then a pointer to the next node

- ``std_stack_t_node_t * create_std_stack_t_node_t(void * data, std_stack_t_node_t * next);``:
    - This function will create and return a stack node

- ``void init_std_stack_t(std_stack_t * stack);``:
    - This function initializes a stack and its members by taking in a pointer to the stack

- ``std_stack_t_node_t peek_std_stack_t(std_stack_t * stack);``:
    - This function returns the topmost node of the stack

- ``void add_to_std_stack_t(std_stack_t * stack, std_stack_t_node_t * node);``:
    - Adds a pointer to a ``std_stack_t_node_t`` to the stack to the top

- ``int pop_from_std_stack_t(std_stack_t * stack);``:
    - Removes the topmost node and the node the topmost node was pointing to becomes the topmost node 


