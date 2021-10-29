#include <stdio.h>
#include "../include/ht.h"

int main(void) {
    ht_t table = create_ht(100);
    
    insert_to_ht(&table, "one", 1);
    insert_to_ht(&table, "two", 2);
    insert_to_ht(&table, "three", 3);
    int x = get_from_ht(table, "one", int); 
    rm_from_ht(&table, "one");
    printf("%d %d\n", x, get_from_ht(table, "two", int));
    
    rm_ht(&table);
}
