#include <queue.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    clock_t start_time = clock();
    
    std_queue_t queue;
    init_std_queue_t(&queue);
    add_to_std_queue_t(&queue, 
		       &((std_queue_t_node_t) { .m_data = (void *) 10, 
					      .m_next = NULL }) );
    add_to_std_queue_t(&queue, 
		       &((std_queue_t_node_t) { .m_data = (void *) 30, 
					      .m_next = NULL }) );




    printf("Size Of Queue: %d\n", (int) queue.m_size);

    double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
    printf("Done in %f seconds\n", elapsed_time);
}


