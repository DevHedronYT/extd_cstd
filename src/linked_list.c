#include <linked_list.h>
#include <stdlib.h>

void init_std_ll_t_node_t(std_ll_t_node_t * node, void * data, std_ll_t_node_t * next, const char * type) {
    node -> m_data = data;
    node -> m_next = next;
    node -> m_type = type;
}


std_ll_t_node_t * create_std_ll_t_node_t(void * data, std_ll_t_node_t * next, const char * type) {
    std_ll_t_node_t * node = NULL; 
    node -> m_data = data;
    node -> m_next = next;
    node -> m_type = type; 

    return node;
}

void init_std_ll_t(std_ll_t * ll) {
    ll -> m_head = NULL;
    ll -> m_last_node  = NULL;
    ll -> m_size = 1;
}

int std_ll_t_insert_at_beginning(std_ll_t * ll, std_ll_t_node_t * node) {
    if (ll -> m_head == NULL) {
        ll -> m_head = node;
        ll -> m_last_node = ll -> m_head;
        return 1;
    }

    ll -> m_head = node;
    ll -> m_size += 1;
    return 0;
}

int std_ll_t_insert_at_end(std_ll_t * ll, std_ll_t_node_t * node) {
    if (ll -> m_head == NULL) {
        std_ll_t_insert_at_beginning(ll, node);
        return 1;
    }

    ll -> m_last_node -> m_next = node;
    ll -> m_last_node = ll -> m_last_node -> m_next;
    ll -> m_size += 1;
    return 0;
}

int std_ll_t_remove(std_ll_t * ll, std_ll_t_node_t * remove_node) {
    if (ll -> m_head == NULL) {
        return -1;
    }

    std_ll_t_node_t * node = ll -> m_head;
    int index = 0;
    while (index < ll -> m_size && node != NULL) {
        if (remove_node -> m_data == node -> m_data && remove_node -> m_type == node -> m_type) {
        
            for (int i = index; i < ll -> m_size - 1; i++) {
            node -> m_data = node -> m_next -> m_data;
            node = node -> m_next; 
            }
            ll -> m_size -= 1;


            return 0;
        }

        
        if (node -> m_next != NULL) node = node -> m_next;
            index += 1;
    }

    return -1;
}

