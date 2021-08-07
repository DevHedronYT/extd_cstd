#include <queue.h>
#include <stdlib.h>
   
emp init_std_queue_t_node_t(std_queue_t_node_t * node, ret data, std_queue_t_node_t * next) {
    node -> m_data = data;
    node -> m_next = next;
}

emp init_std_queue_t(std_queue_t * queue) {
    queue -> m_end = NULL;
    queue -> m_size = 0;
}

emp add_to_std_queue_t(std_queue_t * queue, std_queue_t_node_t * node) {
    node -> m_next = queue -> m_end;
    queue -> m_end = node;
    queue -> m_size += 1;
}

i32 pop_from_std_queue_t(std_queue_t * queue) {
    if (queue -> m_end == NULL) return -1; 
    queue -> m_end = queue -> m_end -> m_next;
    return 0;
}

std_queue_t_node_t * create_std_queue_t_node_t(ret data, std_queue_t_node_t * next) {
    std_queue_t_node_t * node = NULL;
    node -> m_data = data;
    node -> m_next = next;

    return node;
}

std_queue_t_node_t peek_std_queue_t(std_queue_t * queue) {
    return *queue -> m_end; 
}
