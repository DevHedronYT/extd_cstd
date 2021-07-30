#include <queue.h>
#include <stdio.h>
#include <timer.h>

int main(void) {
    std_timer_t timer;
    init_std_timer_t(&timer);
    start(&timer);

    std_queue_t queue;
    init_std_queue_t(&queue);
    add_to_std_queue_t(&queue, 
		       &((std_queue_t_node_t) { .m_data = (void *) 10, 
					      .m_next = NULL }) );
    add_to_std_queue_t(&queue, 
		       &((std_queue_t_node_t) { .m_data = (void *) 30, 
					      .m_next = NULL }) );




    printf("Size Of Queue: %d\n", (int) queue.m_size);

    tick(&timer);
    printf("[Time Took (s)]: %f\n", timer.m_time_passed);

}


