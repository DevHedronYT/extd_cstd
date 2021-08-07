#ifndef _C_STD_LLIST

    #define _C_STD_LLIST

    #include <types.h>

    typedef struct _std_ll_t_node_t {
	    ret                       m_data;
        struct _std_ll_t_node_t * m_next;
        const str                 m_type;
    } std_ll_t_node_t;

    typedef struct {
        std_ll_t_node_t * m_head;
        std_ll_t_node_t * m_last_node;
        i32               m_size;
    } std_ll_t;

    emp init_std_ll_t_node_t        (std_ll_t_node_t * node, ret data, std_ll_t_node_t * next, const str type);
    emp init_std_ll_t               (std_ll_t * ll);
    i32 std_ll_t_insert_at_end      (std_ll_t * ll, std_ll_t_node_t * data);
    i32 std_ll_t_insert_at_beginning(std_ll_t * ll, std_ll_t_node_t * data);
    i32 std_ll_t_remove             (std_ll_t * ll, std_ll_t_node_t * remove_node);


    std_ll_t_node_t * create_std_ll_t_node_t(ret data, std_ll_t_node_t * next, const str type); 

#endif 

