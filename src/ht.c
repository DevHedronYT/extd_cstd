#include <ht.h>
#include <str.h>
#include <stdlib.h>

// - Add collision handling -> linear probing 
// - More functionality:
//  - Add          O(1)
//  - Remove       O(1) 
//  - Get          O(1)
//  - Expand       O(n)
// - Good hash function

// Capacity MUST BE power of 2

ht_t create_ht(u32 capacity) {
    ht_t table;
    table.data = calloc(capacity, sizeof(ht_item_t*));
    table.len = 0;
    table.capacity = capacity;
    return table;
}

#define FNV_OFFSET 14695981039346656037
#define FNV_PRIME 1099511628211
u64 hash_id(const char * id) {
    u64 hash = FNV_OFFSET;
    for (const char * p = id; *p; p++) {
        hash ^= (u64)(u08)(*p);
        hash *= FNV_PRIME;
    }
    return hash;
}

// Capacity MUST BE power of 2
void increase_ht_capacity(ht_t * ht, u32 capacity) {
    ht_t new_ht;
    new_ht.data = calloc(capacity, sizeof(ht_item_t*));
    new_ht.len = 0;
    new_ht.capacity = capacity;
    for (u64 i = 0; i < ht -> capacity; i++) {
        if (ht -> data[i] -> val != NULL) {
            insert_to_ht(&new_ht, ht -> data[i] -> id, ht -> data[i] -> val);
        }
    }

    rm_ht(ht);
    ht = &new_ht;
}


void insert_to_ht(ht_t * ht, const char * id, void * data) {
    ht_item_t * item = calloc(1, sizeof(ht_item_t));
    item -> hash = hash_id(id);
    item -> id = id;
    item -> val = data;
    u64 index = item -> hash & (u64)(ht -> capacity - 1);

    ht_item_t * current = ht -> data[index];
    while (current != NULL) {
        index++;
        current = ht -> data[index];
    }

    if (index > ht -> capacity) {
        increase_ht_capacity(ht, ht -> capacity * 2);
        ht -> data[index] = item;
    }

    if (ht -> data[index] == NULL) {
        ht -> data[index] = item;
    } 

    ht -> len++;   
} 

void * get_from_ht(ht_t ht, const char * id) {
    u64 index = hash_id(id) & (u64)(ht.capacity - 1); 
    ht_item_t * data = ht.data[index];
        
    if (data == NULL) {
        return NULL;
    }

    if (data -> val == NULL) {
        return NULL;
    }

    while (str_compare(data -> id, id) != 1) {
        index++; 
        data = ht.data[index]; 
    }

    if (data -> val != NULL && str_compare(data -> id, id)) {
        return data -> val; 
    }

    return NULL;
}


u64 rm_from_ht(ht_t * ht, const char * id) {
    u64 index = hash_id(id) & (u64)(ht -> capacity - 1); 
    ht_item_t * data = ht -> data[index];
    
    if (data -> val == NULL) {
        return 0;
    }

    while (str_compare(data -> id, id) != 1) {
        index++; 
        data = ht -> data[index]; 
    }

    if (data -> val != NULL && str_compare(data -> id, id)) {
        data = NULL;
        ht -> data[index] = NULL;
    }
    return index;
}


void rm_ht(ht_t * ht) {
    for (u32 i = 0; i < ht -> capacity; i++) {
        free(ht -> data[i]);
    }
    free(ht -> data);   
}



