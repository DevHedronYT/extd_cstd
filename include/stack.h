#ifndef _C_STD_STACK

    #define _C_STD_STACK 
    
    typedef struct _std_stack_t_node_t {
        void * m_data;
        struct _std_stack_t_node_t * m_next;
    } std_stack_t_node_t; 

    typedef struct {
        std_stack_t_node_t * m_top;
        int m_size;
    } std_stack_t;
    
    void init_std_stack_t_node_t(std_stack_t_node_t * node, void * data, std_stack_t_node_t * next);
    std_stack_t_node_t * create_std_stack_t_node_t(void * data, std_stack_t_node_t * next);
    void init_std_stack_t(std_stack_t * stack);
    std_stack_t_node_t peek_std_stack_t(std_stack_t * stack);
    void add_to_std_stack_t(std_stack_t * stack, std_stack_t_node_t * node);
    int pop_from_std_stack_t(std_stack_t * stack);

#endif

