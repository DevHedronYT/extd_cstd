#ifndef _C_STD_STACK

    #define _C_STD_STACK 
    
    #include <types.h>

    typedef struct _std_stack_t_node_t {
        ret                          m_data;
        struct _std_stack_t_node_t * m_next;
    } std_stack_t_node_t; 

    typedef struct {
        std_stack_t_node_t * m_top;
        i32                  m_size;
    } std_stack_t;
    
    emp init_std_stack_t_node_t(std_stack_t_node_t * node, ret data, std_stack_t_node_t * next);
    emp init_std_stack_t       (std_stack_t * stack);
    emp add_to_std_stack_t     (std_stack_t * stack, std_stack_t_node_t * node);
    i32 pop_from_std_stack_t   (std_stack_t * stack);

    std_stack_t_node_t * create_std_stack_t_node_t(ret data, std_stack_t_node_t * next);
    std_stack_t_node_t peek_std_stack_t           (std_stack_t * stack);

#endif

