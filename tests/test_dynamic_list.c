#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <dynamic_list.h>

int main(void) {
    std_dynamic_list_t list;
    init_std_dynamic_list_t(&list);
    
    long n = 2;

    add_elem_to_std_dynamic_list_t(&list, (void *) n);
    
    for (int i = 0; i < list.m_r_size; i++) {
	printf("elem: %lu\n", (unsigned long) list.m_data[i]);
    }


    add_elem_to_std_dynamic_list_t(&list, (void *) (n + 2));

    remove_elem_from_std_dynamic_list_t(&list, 1);

    add_elem_to_std_dynamic_list_t(&list, (void *) (n + 3));
    for (int i = 0; i < list.m_r_size; i++) {
	printf("elem : %lu\n", (unsigned long) list.m_data[i]);
    }


}


