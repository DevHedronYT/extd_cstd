#ifndef _LIST_H

    #define _LIST_H
   
    #include <types.h>

    typedef struct {
        ret_t * data;
        u32_t   len;
        u32_t   idx;
    } list_t;

    list_t create_list(u32_t capacity);
    emp_t __push_to_list(list_t * list, ret_t data);
    emp_t remove_from_list_at(list_t * list, u32_t idx);
    emp_t __remove_from_list(list_t * list, ret_t data);
    i32_t __get_in_list_t(list_t * list, ret_t data);
    emp_t free_list(list_t * list);

    #define push_to_list(list, data) \
        __push_to_list(list, (ret_t) data)

    #define get_at_list_t(list, index) \
        list.data[index]

    #define get_data(list, data) \
        get_at_list_t(list, __get_in_list_t(&list, (ret_t)data))

    #define remove_from_list(list, data) \
        __remove_from_list(list, (ret_t) data)



#endif
