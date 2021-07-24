#include <stdio.h>
#include <linked_list.h>

int main(void) {
    ll_t ll;
    init_ll_t(&ll);

    node_t n = { .m_data = (void *) 123, .m_next = NULL, .m_type = "i" };
    node_t u = { .m_data = (void *) 24,  .m_next = &n  , .m_type = "i" };
    node_t x = { .m_data = (void *) 21,  .m_next = &u  , .m_type = "i" };
    node_t y = { .m_data = (void *) 65,  .m_next = &x  , .m_type = "i" };


    ll_t_insert_at_beginning(&ll, &n);
    ll_t_insert_at_beginning(&ll, &u);
    ll_t_insert_at_beginning(&ll, &x);
    ll_t_insert_at_beginning(&ll, &y);

    int index = 0;
    node_t * node = ll.m_head;

    while (index < ll.m_size) {
	printf("e: %d\n", (int) node -> m_data);
	node = node -> m_next;
	index += 1;
    }

    printf("\n");
    node_t remove_node = { .m_data = (void *) 'A', .m_next = NULL, .m_type = "c" };
    ll_t_remove(&ll, &remove_node);

    index = 0;
    node = ll.m_head;

    while (index < ll.m_size) {
	printf("e: %d\n", (int) node -> m_data);
	node = node -> m_next;
	index += 1;
    }

    printf("%d\n", (int) ll.m_size);
}


