#ifndef _HT_H
    
    #include <types.h>

    typedef struct {
        const str_t id;
        u64_t       hash;
        ret_t       val;
    } ht_item_t;

    typedef struct {
        ht_item_t ** data;
        u32_t        len;
        u32_t        capacity;
    } ht_t; 

    ht_t  create_ht(u32_t capacity);
    u64_t hash_id(const str_t id);
    emp_t increase_ht_capacity(ht_t * ht, u32_t capacity);
    emp_t __insert_to_ht(ht_t * ht, const str_t id, ret_t data);
    ret_t __get_from_ht(ht_t ht, const str_t id);
    u32_t rm_from_ht(ht_t * ht, const str_t id);
    emp_t rm_ht(ht_t * ht);

    #define insert_to_ht(ht, id, data) \
        __insert_to_ht(ht, id, (ret_t) data)

    #define get_from_ht(ht, id, type) \
        (type)__get_from_ht(ht, id)


#endif
