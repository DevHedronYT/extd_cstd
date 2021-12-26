#ifndef _LIST_H_
    #define _LIST_H_
    #include <types.h>

    typedef struct {
        void ** data;
        u32     len;
        u32     idx;
    } list_t;

    list_t create_list(u32 capacity);
    void   insert_to_list(list_t * list, void * data);
    i32    get_list_idx(list_t list, void * data);
    void   rm_from_list_at(list_t * list, u32 idx);
    void   rm_from_list(list_t * list, void * data);
    void   free_list(list_t * list);

    #define get_at_list(list, index) \
        list.data[index]

    #define get_data_in_list(list, data) \
        get_at_list(list, get_list_idx(&list, (void *)data))

    #define remove_from_list(list, data) \
        rm_from_list(list, (void *) data)


#endif
