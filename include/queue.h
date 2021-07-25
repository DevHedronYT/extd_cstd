#ifndef _C_STD_QUEUE

    #define _C_STD_QUEUE
    
    typedef struct _std_queue_t_node_t {
	void * m_data;
	struct _std_queue_t_node_t * m_next;
    } std_queue_t_node_t; 

    typedef struct {
	std_queue_t_node_t * m_end;
	int m_size;
    } std_queue_t;
    
    void init_std_queue_t_node_t(std_queue_t_node_t * node, void * data, std_queue_t_node_t * next);
    void init_std_queue_t(std_queue_t * queue);
    std_queue_t_node_t peek_std_queue_t(std_queue_t * queue);
    void add_to_std_queue_t(std_queue_t * queue, std_queue_t_node_t * node);
    int pop_from_std_queue_t(std_queue_t * queue);

#endif


