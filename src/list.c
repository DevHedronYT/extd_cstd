#include <list.h>
#include <stdlib.h>

list_t create_list(u32 capacity) {
    list_t list;
    list.data = calloc(capacity, sizeof(void*)); 
    list.len = capacity;
    list.idx = 0;
    return list;
}

void insert_to_list(list_t * list, void * data) {
    if (list -> idx + 1 > list -> len) {   
        list -> len += 10;
        list -> data = realloc(list -> data, list -> len);

    }
    list -> data[list -> idx] = data;
    list -> idx++; 

}


void rm_from_list_at(list_t * list, u32 idx) {
    while (idx + 1 < list -> len) {
        list -> data[idx] = list -> data[idx + 1]; 
    }      
}

void rm_from_list(list_t * list, void * data) {
    u32 idx = get_list_idx(*list, data);
    rm_from_list_at(list, idx);
}

i32 get_list_idx(list_t list, void * data) {
    for (i32 i = 0; i < list.len - 1; i++) {
        if (list.data[i] == data) {
            return i;
        }
    }

    return 0x0;
}

void free_list(list_t * list) {
    for (i32 i = 0; i < list -> len - 1; i++) {
        free(list -> data[i]);
    } 

    free(list -> data);
}


