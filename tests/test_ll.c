#include <stdio.h>
#include <linked_list.h>
#include <time.h>

int main(void) {
    clock_t start_time = clock();

    std_ll_t ll;
    init_std_ll_t(&ll);

    std_ll_t_node_t n = { .m_data = (void *) 123, .m_next = NULL, .m_type = "i" };
    std_ll_t_node_t u = { .m_data = (void *) 24,  .m_next = &n  , .m_type = "i" };
    std_ll_t_node_t x = { .m_data = (void *) 21,  .m_next = &u  , .m_type = "i" };
    std_ll_t_node_t y = { .m_data = (void *) 65,  .m_next = &x  , .m_type = "i" };


    std_ll_t_insert_at_beginning(&ll, &n);
    std_ll_t_insert_at_beginning(&ll, &u);
    std_ll_t_insert_at_beginning(&ll, &x);
    std_ll_t_insert_at_beginning(&ll, &y);

    int index = 0;
    std_ll_t_node_t * node = ll.m_head;

    while (index < ll.m_size) {
	printf("Elements: %d\n", (int) node -> m_data);
	node = node -> m_next;
	index += 1;
    }

    printf("\n");
    std_ll_t_node_t remove_node = { .m_data = (void *) 'A', .m_next = NULL, .m_type = "c" };
    std_ll_t_remove(&ll, &remove_node);

    index = 0;
    node = ll.m_head;

    while (index < ll.m_size) {
	printf("Elements After Removal: %d\n", (int) node -> m_data);
	node = node -> m_next;
	index += 1;
    }

    printf("%d\n", (int) ll.m_size);

    double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
    printf("Done in %f seconds\n", elapsed_time);

}


