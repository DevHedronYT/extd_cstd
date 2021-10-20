#include <list.h>
#include <stdlib.h>

list_t create_list(u32_t capacity) {
    list_t list;
    list.data = (void**) calloc(capacity, sizeof(void*)); 
    list.len = capacity;
    list.idx = 0;
    return list;
}

emp_t push_to_list(list_t * list, ret_t data) {
    if (list -> idx + 1 > list -> len) {   
        list -> len += 10;
        list -> data = (ret_t*) realloc(list -> data, list -> len);

    }
    list -> data[list -> idx] = data;
    list -> idx++;        

}


emp_t remove_from_list_at(list_t * list, u32_t idx) {
    while (idx + 1 < list -> len) {
        list -> data[idx] = list -> data[idx + 1]; 
    }      
}

emp_t remove_from_list(list_t * list, ret_t data,
                      i08_t (* compare_func)(ret_t x, ret_t y)) {
    u32_t idx = __get_in_list_t(list, data, compare_func);
    remove_from_list_at(list, idx);
}

i32_t __get_in_list_t(list_t * list, ret_t data, 
                     i08_t (* compare_func)(ret_t x, ret_t y)) {
    for (int i = 0; i < list -> len - 1; i++) {
        if (compare_func == NULL) {
            if (list -> data[i] == data) {
                return i;
            }
        
        }
        else {
            if (compare_func(data, &data[i])) {
                return i;
            }
        }
    }

    return 0x0;
}

emp_t free_list(list_t * list) {
    for (int i = 0; i < list -> len - 1; i++) {
        free(list -> data[i]);
    } 

    free(list -> data);
}


