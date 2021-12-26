#ifndef _HT_H_
    #define _HT_H_ 
    #include <types.h>

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
    ht_t   create_ht(u32 capacity);
    void   insert_to_ht(ht_t * ht, const char * id, void * data); 
    void * get_from_ht(ht_t ht, const char * id);
    u64    rm_from_ht(ht_t * ht, const char * id);
    void   rm_ht(ht_t * ht);

#endif
