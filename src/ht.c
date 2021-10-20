#include <ht.h>
#include <stdlib.h>

// - Add collision handling -> linear probing 
// - More functionality:
//  - Add          O(1)
//  - Remove       O(1) 
//  - Get          O(1)
//  - Expand       O(n)
// - Good hash function

ht_t create_ht(u32_t capacity) {
    ht_t table;
    table.data = (ht_item_t *) calloc(capacity, sizeof(ht_item_t)); 
    table.len = 0;
    table.capacity = capacity;
    return table;
}

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL
u64_t hash_id(const str_t id) {
    uint64_t hash = FNV_OFFSET;
    for (const char * p = id; *p; p++) {
        hash ^= (uint64_t)(unsigned char)(*p);
        hash *= FNV_PRIME;
    }
    return hash;
}

emp_t increase_ht_capacity(ht_t * ht, u32_t capacity) {
    ht_t new_ht;
    new_ht.data = (ht_item_t *) calloc(capacity, sizeof(ht_item_t));
    new_ht.len = 0;
    new_ht.capacity = capacity;
    for (u64_t i = 0; i < ht -> capacity; i++) {
        if (ht -> data[i].val != NULL) {
            __insert_to_ht(&new_ht, ht -> data[i].id, ht -> data[i].val);
        }
    }
    free(ht -> data);
    ht = &new_ht;
}

emp_t __insert_to_ht(ht_t * ht, const str_t id, ret_t data) {
    ht_item_t item = { .id = id, .hash = hash_id(id), .val = data };
    u64_t index = item.hash & (u64_t)(ht -> capacity - 1);

    ret_t current = ht -> data[index].val;
    while (current != NULL) {
        index++;
        current = ht -> data[index].val;
    }

    if (index > ht -> capacity) {
        increase_ht_capacity(ht, ht -> capacity * 4);
        ht -> data[index] = item;
    }

    if (ht -> data[index].val == NULL) {
        ht -> data[index] = item;
    } 
    else {
        index++;
    }

    ht -> len++;
}

ret_t __get_from_ht(ht_t * ht, const str_t id) {
    u64_t index = hash_id(id) & (u64_t)(ht -> capacity - 1); 
    ht_item_t data = ht -> data[index];
    
    if (data.val == NULL) {
        return NULL;
    }

    while (data.id != id) {
        index++; 
        data = ht -> data[index]; 
    }

    if (data.val != NULL && data.id == id) {
        return data.val; 
    }

    return NULL;
}

u32_t rm_from_ht(ht_t * ht, const str_t id) {
    u64_t index = hash_id(id) & (u64_t)(ht -> capacity - 1); 
    ht_item_t * data = &ht -> data[index];
    
    if (data -> val == NULL) {
        return 0;
    }

    while (data -> id != id) {
        index++; 
        data = &ht -> data[index]; 
    }

    if (data -> val != NULL && data -> id == id) {
        data = (ht_item_t *) NULL;
    }
    return index;
}

emp_t rm_ht(ht_t * ht) {
    free(ht -> data);
}


