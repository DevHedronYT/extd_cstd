# c_std_lib
Implementations Of DSA And More. Have fun looking at the code, currently implemented:
    - Binary Search Trees
    - Dynamic Lists
    - File Loading
    - Hash Tables
    - Linked Lists
    - Maths Engine (Very Incomplete)
    - Queues
    - Stacks
    - Strings
    - Timers
    - Types
    - Utils

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

> This file is to be included for the dynamic list data structure and operations on it

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

> This file is to be included if you need to load a file

- ``char * std_load_text_file(const char * name);``:
    - Loads text file

### Hash Table - ``hash_table.h``:

> This file is to be included for the hash table data structure and operations on it

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

### Strings - ``str.h``:

> This file is to be included for string functions

- ``#define str char *``:
    - Redefines ``char *`` to ``str``
  
- ``int std_str_length(const str str_one);``:
    - Returns length of string

- ``int std_str_compare(const str str_one, const str str_two);``:
    - Compares 2 strings and returns 1 if they are the same

- ``str std_str_concat(const str str_one, const str str_two);``:
    - Concatenates a string to another string

- ``int std_str_subchar(str str_one, char letter);``:
    - Checks if the string passed in contains a certain letter which you also passed in, and if it does, it returns 1

- ``int std_str_substring(const str str_one, const str str_two);``:
    - Checks if a substring exists inside a string and if it does, returns 1

- ``int std_str_starts_with(const str str_one, const str str_two);``:
    - Checks if a string starts with another string or not, returns 1 if it does

- ``int std_str_ends_with(str str_one, str str_two);``:
    - Checks if a string ends with another string or not, returns 1 if it does

- ``str std_str_reverse(str str_one);``:
    - Reverses a string

- ``str std_str_split(const str str_one, char c);``:
    - Splits a string at a certain character


### Timer - ``timer.h``:

> This file is to be included for timing programs

- ``struct std_timer_t``:
    - This struct contains a ``double`` which has the time passed and a ``clock_t`` to calculate the time passed using ``time.h``

- ``void init_std_timer(std_timer_t * timer);``:
    - This function takes in a pointer to ``std_timer_t`` and then initializes its ``m_time_passed`` value to ``0`` 

- ``void start(std_timer_t * timer);``:
    - This function starts the timer or gets the current time

- ``void tick(std_timer_t * timer);``:
    - This function essentially just gets the time passed by subtracting the current time from the last time.

### Utils - ``util.h``:
> This file is to be included for colored printing in terminals that support ANSI colors

- ``#define std_set_output_bg_color(x)``:
    - Takes in another macro which is in the file, like BGCWHITE, and sets the background of the output text to white until set to default

- ``#define std_print_n(msg, ...);``:
    - Takes in a string ``msg`` and the rest as ``__VA_ARGS__``, to use it, ``std_print_n("Hello", NULL)`` and another way to use it ``std_print_n("int x: %d", x);`` The string printed is in the color you have configured for the text in your terminal

- ``#define std_print_t(msg, ...);``:
    - Does the same thing as ``std_print_n`` but prints out the current time as well

- ``#define std_print_info(msg, ...);``:
    - Does the same thing as ``std_print_t`` but prints the text supplied to it in a green color with the current time and ``[INFO]``

- ``#define std_print_error(msg, ...);``:
    - Prints text supplied to it in red color with current time and ``[ERROR]``

- ``#define std_print_warning(msg, ...);``:
    - Prints text supplied to it in yellow color with current time and ``[WARNING]``

- ``#define std_print_fatal_error(msg, ...);``:
    - Prints text supplied to it in red color with current time and ``[FATAL ERROR]`` and also makes the text bold

- ``#define std_print_important(msg, ...);``:
    - Prints text supplied to it blue color with current time and ``[IMPORTANT]`` and also adds underline to the text 


### Types - ``types.h``:

> This file is to be included for using types

- ``#define i08_t  int8_t``:
    - 8-bit integer

- ``#define i16_t  int16_t``:
    - 16-bit integer

- ``#define i32_t int32_t``:
    - 32-bit integer

- ``#define i64_t  int64_t``:
    - 64-bit integer

- ``#define f32_t float``:
    - 32-bit float

- ``#define f64_t double``:
    - 64-bit float

- ``#define u08_t uint8_t``:
    - 8-bit unsigned integer

- ``#define u16_t uint16_t``:
    - 16-bit unsigned integer

- ``#define u32_t uint32_t``:
    - 32-bit unsigned integer

- ``#define u64_t uint64_t``:
    - 64-bit unsigned integer

- ``#define emp_t void``:
    - Void

- ``#define ret_t void *``:
    - Void Pointer

- ``#define str_t char *``:
    - String

- ``#define chr_t char``:
    - Char
