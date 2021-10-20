#ifndef _HT_H
    
    #include <types.h>

    /*
    struct ht_item_t:
        const char * id;
        32-bit int hash;
        void *      val;

    struct ht_t:
        ht_item_t * data;
        u32_t len;
        u32_t capacity;

    // Create hash table with certain 
    // capacity -> O(1) 
    //  Takes in a unsigned int capacity and 
    //  returns a ht_t
    ht_t create_ht(u32_t capacity);

    
    // Hash a const char * id -> O(n) 
    //  Takes in a const char * id
    //  and returns a unsigned int
    //  hash
    u64_t hash_id(const str_t id);

    // Increase hash table size -> O(n) 
    //  Takes in ht_t pointer to table
    //  whose size you want to increase
    //  and the new unsigned int capacity
    emp_t increase_ht_capacity(ht_t * ht, u32_t capacity);


    // Insert to hash table [NOT TO BE USED] -> O(1)
    //  Takes in a ht_t pointer to table, const char * id
    //  and void pointer to the data
    //  DO NOT USE THIS USE THE OTHER ONE
    emp_t __insert_to_ht(ht_t * ht, const str_t id, ret_t data);

    // Get from hash table [NOT TO BE USED] -> O(1)
    //  Takes in a ht_t pointer to table 
    //  and takes in a the const char * id
    //  for the data you want to retrieve
    //  DO NOT USE THIS USE THE OTHER ONE
    ret_t __get_from_ht(ht_t * ht, const str_t id);

    // Remove from hash table -> O(1)
    //  Takes in a pointer to the hash table
    //  and const char * id for the data you 
    //  want to be removed
    u32_t rm_from_ht(ht_t * ht, const str_t id);

    // Frees memory allocated for the 
    // ht_item_t
    //  Takes in a pointer to ht_t or the 
    //  table you want to free
    emp_t rm_ht(ht_t * ht);

    // Inserts to hash table
    //  Takes in a pointer to ht_t as the
    //  table, takes in const char * id, 
    //  and the data or void pointer
    insert_to_ht(ht, id, data)

    // Gets data from hash table cast
    // to certain type
    //  Takes in a pointer to ht_t 
    //  which is the table and also 
    //  takes in a const char * id
    //  and also takes in the type
    get_from_ht(ht, id, type)
    */

    typedef struct {
        const str_t id;
        u64_t       hash;
        ret_t       val;
    } ht_item_t;

    typedef struct {
        ht_item_t * data;
        u32_t       len;
        u32_t       capacity;
    } ht_t; 

    ht_t create_ht(u32_t capacity);
    u64_t hash_id(const str_t id);
    emp_t increase_ht_capacity(ht_t * ht, u32_t capacity);
    emp_t __insert_to_ht(ht_t * ht, const str_t id, ret_t data);
    ret_t __get_from_ht(ht_t * ht, const str_t id);
    u32_t rm_from_ht(ht_t * ht, const str_t id);
    emp_t rm_ht(ht_t * ht);

    #define insert_to_ht(ht, id, data) \
        __insert_to_ht(id, (void *) data, ht)

    #define get_from_ht(ht, id, type) \
        (type) __get_data_from_ht(id, ht)


#endif
