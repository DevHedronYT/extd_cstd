#include <stack.h>
#include <stdlib.h>

void init_std_stack_t_node_t(std_stack_t_node_t * node, void * data, std_stack_t_node_t * next) {
    node -> m_data = data;
    node -> m_next = next;
}

std_stack_t_node_t * create_std_stack_t_node_t(void * data, std_stack_t_node_t * next) {
    std_stack_t_node_t * node = NULL;
    node -> m_data = data;
    node -> m_next = next;

    return node;
}

void init_std_stack_t(std_stack_t * stack) {
    stack -> m_top = NULL;
    stack -> m_size = 0;
}

std_stack_t_node_t peek_stack_t(std_stack_t * stack) {
    return *(stack -> m_top);
}

void add_to_std_stack_t(std_stack_t * stack, std_stack_t_node_t * node) {
    std_stack_t_node_t * next_node = stack -> m_top;
    node -> m_next = next_node;
    stack -> m_top = node;
}

int pop_from_std_stack_t(std_stack_t * stack) {
    if (stack -> m_top == NULL) return -1;
    stack -> m_top = stack -> m_top -> m_next;
    return 0;
}

