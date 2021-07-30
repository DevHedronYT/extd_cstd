#include <stack.h>
#include <stdio.h>
#include <timer.h>

int main(void) {
    std_timer_t timer;
    init_std_timer_t(&timer);
    start(&timer);

    std_stack_t stack;
    
    std_stack_t_node_t node_top;
    std_stack_t_node_t node_top_new;

    init_std_stack_t_node_t(&node_top, (void *) 23, NULL);
    add_to_std_stack_t(&stack, &node_top);

    init_std_stack_t_node_t(&node_top_new, (void *) 43, NULL);
    add_to_std_stack_t(&stack, &node_top_new);

    printf("Stack Top Before Pop: %d\n", (int) stack.m_top -> m_data);
    pop_from_std_stack_t(&stack);
    printf("Stack Top After Pop: %d\n", (int) stack.m_top -> m_data);


    tick(&timer);
    printf("[Time Took (s)]: %f\n", timer.m_time_passed);

}
