#ifndef _C_STD_LIST

    #define _C_STD_LIST
   
    #include <types.h>

    typedef struct {
        ret       m_data;
        const str m_type;
    } std_dynamic_list_t_node_t;

    typedef struct {
        i32   m_size;
        ret * m_data;
        i32   m_r_size;
    } std_dynamic_list_t;

    emp init_std_dynamic_list_t_node_t        (std_dynamic_list_t_node_t * node, ret data, const str type);
    emp init_std_dynamic_list_t               (std_dynamic_list_t * list);
    emp add_elem_to_std_dynamic_list_t        (std_dynamic_list_t * list, std_dynamic_list_t_node_t * node);
    emp remove_elem_from_std_dynamic_list_t   (std_dynamic_list_t * list, std_dynamic_list_t_node_t * node);
    emp remove_elem_from_std_dynamic_list_t_at(std_dynamic_list_t * list, i32 index);
    emp uninit_std_dynamic_list_t             (std_dynamic_list_t * list);


    std_dynamic_list_t_node_t * create_std_dynamic_list_t_node_t(ret data, const str type);
    ret get_std_dynamic_list_t_node_t_data_value_at             (std_dynamic_list_t * list, i32 index);


#endif
