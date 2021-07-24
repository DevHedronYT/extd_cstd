#include <linked_list.h>
#include <stdlib.h>
#include <stdio.h>

void init_node_t(node_t * node, void * data, node_t * next) {
    node -> m_data = data;
    node -> m_next = next;
}

void init_ll_t(ll_t * ll) {
    ll -> m_head = NULL;
    ll -> m_last_node  = NULL;
    ll -> m_size = 1;
}

void ** ll_t_to_arr(ll_t * ll) {
    void ** arr = malloc(sizeof(ll -> m_size) * sizeof(void *));

    if (ll -> m_head == NULL) {
	return arr;
    }

    node_t * node = ll -> m_head;
    int index = 0;
    while (node != NULL) {
	arr[index] = node -> m_data;
	node = node -> m_next;
    }

    return arr;
}


int ll_t_insert_at_beginning(ll_t * ll, node_t * node) {
    if (ll -> m_head == NULL) {
	ll -> m_head = node;
	ll -> m_last_node = ll -> m_head;
	return 0;
    }

    ll -> m_head = node;
    ll -> m_size += 1;
}

int ll_t_insert_at_end(ll_t * ll, node_t * node) {
    if (ll -> m_head == NULL) {
	ll_t_insert_at_beginning(ll, node);
	return 0;
    }

    ll -> m_last_node -> m_next = node;
    ll -> m_last_node = ll -> m_last_node -> m_next;
    ll -> m_size += 1;
}

int ll_t_remove(ll_t * ll, node_t * remove_node) {
    if (ll -> m_head == NULL) {
	return -1;
    }

    node_t * node = ll -> m_head;
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

