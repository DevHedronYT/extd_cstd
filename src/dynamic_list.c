#include <dynamic_list.h>
#include <stdlib.h>

emp init_std_dynamic_list_t_node_t(std_dynamic_list_t_node_t * node, ret data, const str type) {
    node -> m_data = data;
    node -> m_type = type;
}

ret get_std_dynamic_list_t_node_t_data_value_at(std_dynamic_list_t * list, i32 index) {
    std_dynamic_list_t_node_t * node = malloc(sizeof(std_dynamic_list_t_node_t));
    node = (std_dynamic_list_t_node_t *) list -> m_data[index];
    return node -> m_data;
}

emp init_std_dynamic_list_t(std_dynamic_list_t * list) {
    list -> m_data  = malloc(sizeof(std_dynamic_list_t_node_t) * 1); 
    list -> m_size = 1;
}

//add_elem_to_std_dynamic_list_t(&list, create_std_dynamic_list_t_node_t((void *) n, "long"));

emp add_elem_to_std_dynamic_list_t(std_dynamic_list_t * list, std_dynamic_list_t_node_t * node) {
    list -> m_data[list -> m_size - 1] = (void *) node;
    list -> m_data = realloc(list -> m_data, list -> m_size + 1);
    list -> m_size += 1;
    list -> m_r_size = list -> m_size - 1;
}

emp remove_elem_from_std_dynamic_list_t_at(std_dynamic_list_t * list, i32 index) {
    list -> m_data[index] = (std_dynamic_list_t_node_t *) 0;
    for (i32 i = index; i < list -> m_size - 1; i++) {
        list -> m_data[i] = list -> m_data[i + 1];
    }

    list -> m_size -= 1;
    list -> m_r_size = list -> m_size - 1;

    list -> m_data = realloc(list -> m_data, list -> m_size);
}

emp remove_elem_from_std_dynamic_list_t(std_dynamic_list_t * list, std_dynamic_list_t_node_t * node) {
    std_dynamic_list_t_node_t * node_cpy = malloc(sizeof(std_dynamic_list_t_node_t));

    for (i32 i = 0; i < list -> m_r_size; i++) {
        node_cpy = (std_dynamic_list_t_node_t *) list -> m_data[i];
        if (node_cpy -> m_data == node -> m_data && node_cpy -> m_type == node -> m_type) {
            list -> m_data[i] = (void *) (NULL);
            for (i32 n = i; n < list -> m_r_size; n++) {
                list -> m_data[n] = list -> m_data[n + 1];
            }
        }

        break;
    }

    list -> m_size -= 1;
    list -> m_r_size = list -> m_size - 1;
    list -> m_data = realloc(list -> m_data, list -> m_size);
}

emp uninit_std_dynamic_list_t(std_dynamic_list_t * list) {
    free(list);
}

std_dynamic_list_t_node_t * create_std_dynamic_list_t_node_t(ret data, const str type) {
    std_dynamic_list_t_node_t * node = malloc(sizeof(std_dynamic_list_t_node_t));

    node -> m_data = data;
    node -> m_type = type;
    
    return node;
}




