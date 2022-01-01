#include <extd_cstd/lib.h>

list_t list_create(u32 capacity) {
    list_t list;
    list.data = calloc(capacity, sizeof(void*)); 
    assert(list.data != NULL);
    list.len = capacity;
    list.idx = 0;
    return list;
}

void list_insert(list_t * list, void * data) {
    assert(list != NULL && data != NULL);
    if (list -> idx + 1 > list -> len) {   
        list -> len += 10;
        void * new_data = realloc(list -> data, list -> len);
        assert(new_data != NULL);
        list -> data = new_data;
    }
    list -> data[list -> idx] = data;
    list -> idx++; 

}

i32 list_get_idx_of(list_t list, void * data) {
    assert(data != NULL);
    for (i32 i = 0; i < list.len - 1; i++) {
        if (list.data[i] == data) {
            return i;
        }
    }

    return 0x0;
}

void list_rm_at(list_t * list, u32 idx) {
    assert(list != NULL);
    while (idx + 1 < list -> len) {
        list -> data[idx] = list -> data[idx + 1]; 
    }      
}

void list_rm_data(list_t * list, void * data) {
    assert(list != NULL && data != NULL);
    u32 idx = list_get_idx_of(*list, data);
    list_rm_at(list, idx);
}

void list_rm(list_t * list) {
    assert(list != NULL);
    for (i32 i = 0; i < list -> len - 1; i++) {
        free(list -> data[i]);
    } 

    free(list -> data);
}


