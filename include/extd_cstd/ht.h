#ifndef HT_H
    #define HT_H 
    #include "./types.h"

    typedef struct {
        const char * id;
        u64          hash;
        void *       val;
    } ht_item_t;

    typedef struct {
        ht_item_t ** data;
        u32        len;
        u32        capacity;
    } ht_t; 

    // Capacity must be a power of 2
    ht_t   ht_create (u32 capacity);
    void   ht_insert (ht_t * ht, const char * id, void * data); 
    void * ht_get    (ht_t * ht, const char * id);
    u64    ht_rm_data(ht_t * ht, const char * id);
    void   ht_rm     (ht_t * ht);

#endif
