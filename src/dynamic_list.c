#include <dynamic_list.h>
#include <stdlib.h>

void init_std_dynamic_list_t(std_dynamic_list_t * list) {
    list -> m_data  = malloc(sizeof(void*) * 1); 
    list -> m_size = 1;
}

void add_elem_to_std_dynamic_list_t(std_dynamic_list_t * list, void * item) {
    list -> m_data[list -> m_size - 1] = item;
    list -> m_data = realloc(list -> m_data, list -> m_size + 1);
    list -> m_size += 1;
    list -> m_r_size = list -> m_size - 1;
}

void remove_elem_from_std_dynamic_list_t(std_dynamic_list_t * list, int index) {
    list -> m_data[index] = (void *) 0;
    for (int i = index; i < list -> m_size - 1; i++) {
	list -> m_data[i] = list -> m_data[i + 1];
    }

    list -> m_size -= 1;
    list -> m_r_size = list -> m_size - 1;

    list -> m_data = realloc(list -> m_data, list -> m_size);
}

void uninit_std_dynamic_list_t(std_dynamic_list_t * list) {
    free(list);
}

