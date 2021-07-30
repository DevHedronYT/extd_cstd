#include <hash_table.h>
#include <stdio.h>
#include <stdlib.h>
#include <timer.h>


int main(void) {
    std_timer_t timer;
    init_std_timer_t(&timer);
    start(&timer);

    std_hash_table_t_node_t node;
    std_hash_table_t_node_t node_two;

    init_std_hash_table_t_node_t(&node, (void*) 65, "one");
    init_std_hash_table_t_node_t(&node_two, (void*) 12, "two");

    std_hash_table_t table;

    init_std_hash_table_t(&table);
    add_pair_to_std_hash_table_t(&table, &node);
    add_pair_to_std_hash_table_t(&table, &node_two);
    

    printf("%d\n", (int) get_std_hash_table_t_node_t_data_value_at(&table, "lol"));

    tick(&timer);
    printf("[Time Took (s)]: %f\n", timer.m_time_passed);
    return 0;
}

