#include <stdio.h>
#include "../include/ht.h"

/*
    ht_t  create_ht(u32_t capacity);
    u64_t hash_id(const str_t id);
    emp_t increase_ht_capacity(ht_t * ht, u32_t capacity);
    emp_t __insert_to_ht(ht_t * ht, const str_t id, ret_t data);
    ret_t __get_from_ht(ht_t ht, const str_t id);
    u32_t rm_from_ht(ht_t * ht, const str_t id);
    emp_t rm_ht(ht_t * ht);

    #define insert_to_ht(ht, id, data)
    #define get_from_ht(ht, id, type) 
*/

int main(void) {
    ht_t table = create_ht(1 << 7);
    
    const char *tests[6] = {"one", 
                           "two",
                           "three",
                           "four",
                           "five",
                           "six"};
    
    
    insert_to_ht(&table, "one", 1);
    insert_to_ht(&table, "two", 2);
    insert_to_ht(&table, "three", "lmfao");
    int x = get_from_ht(table, "one", long); 
    rm_from_ht(&table, "one");
    //int * n = __get_from_ht(table, "two");
    u64_t index = hash_id("two") & (u64_t)(table.capacity - 1);

    printf("%d\n", get_from_ht(table, "one", int));
        
    rm_ht(&table);
}
