#include <stack.h>
#include <stdio.h>

int main(void) {
    std_stack_t stack;
    
    std_stack_t_node_t node_top;
    std_stack_t_node_t node_top_new;

    init_std_stack_t_node_t(&node_top, (void *) 23, NULL);
    add_to_std_stack_t(&stack, &node_top);

    init_std_stack_t_node_t(&node_top_new, (void *) 43, NULL);
    add_to_std_stack_t(&stack, &node_top_new);

    printf("%d\n", (int) stack.m_top -> m_data);
    pop_from_std_stack_t(&stack);
    printf("%d\n", (int) stack.m_top -> m_data);
}
