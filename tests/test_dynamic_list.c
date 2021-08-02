#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <dynamic_list.h>
#include <timer.h>

int main(void) {
    std_timer_t timer;
    init_std_timer_t(&timer);
    start(&timer);

    std_dynamic_list_t list;
    init_std_dynamic_list_t(&list);
    

    add_elem_to_std_dynamic_list_t(&list, create_std_dynamic_list_t_node_t((void *) 3, "long"));
    
    add_elem_to_std_dynamic_list_t(&list, create_std_dynamic_list_t_node_t((void *) 2, "long"));
    
    for (int i = 0; i < list.m_r_size; i++) {
        printf("Element: %lu\n", (long) get_std_dynamic_list_t_node_t_data_value_at(&list, i));
    }

    remove_elem_from_std_dynamic_list_t(&list, create_std_dynamic_list_t_node_t((void *) 2, "long"));

    for (int i = 0; i < list.m_r_size; i++) {
        printf("removedElement: %lu\n", (long) get_std_dynamic_list_t_node_t_data_value_at(&list, i));
    }

    tick(&timer);
    printf("[Time Took (s)]: %f\n", timer.m_time_passed);

}


