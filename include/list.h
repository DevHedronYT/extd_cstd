#ifndef _LIST_H

    #define _LIST_H
   
    #include <types.h>

    typedef struct {
        ret_t * data;
        u32_t   len;
        u32_t   idx;
    } list_t;

    list_t create_list(u32_t capacity);
    emp_t push_to_list(list_t * list, ret_t data);
    emp_t remove_from_list_at(list_t * list, u32_t idx);
    emp_t remove_from_list(list_t * list, ret_t data,
                          i08_t (* compare_func)(ret_t x, ret_t y));
    i32_t __get_in_list_t(list_t * list, ret_t data, 
                          i08_t (* compare_func)(ret_t x, ret_t y));
    emp_t free_list(list_t * list);

    #define get_at_list_t(list, index, type) \
        (type) list.data[index]
    #define get_data(list, data, func, type) \
        get_at_list_t(list, __get_in_list_t(&list, (ret_t)data, func), type)


#endif
