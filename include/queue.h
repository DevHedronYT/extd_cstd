#ifndef _C_STD_QUEUE

    #define _C_STD_QUEUE
   
    #include <types.h>

    typedef struct _std_queue_t_node_t {
        ret                          m_data;
        struct _std_queue_t_node_t * m_next;
    } std_queue_t_node_t; 

    typedef struct {
        std_queue_t_node_t * m_end;
        i32                  m_size;
    } std_queue_t;
    
    emp init_std_queue_t_node_t(std_queue_t_node_t * node, ret data, std_queue_t_node_t * next);
    emp init_std_queue_t       (std_queue_t * queue);
    emp add_to_std_queue_t     (std_queue_t * queue, std_queue_t_node_t * node);
    i32 pop_from_std_queue_t   (std_queue_t * queue);

    std_queue_t_node_t * create_std_queue_t_node_t(ret data, std_queue_t_node_t * next); 
    std_queue_t_node_t peek_std_queue_t           (std_queue_t * queue);

#endif


