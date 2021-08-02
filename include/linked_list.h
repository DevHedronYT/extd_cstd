#ifndef _C_STD_LLIST

    #define _C_STD_LLIST

    typedef struct _std_ll_t_node_t {
	void * m_data;
        struct _std_ll_t_node_t * m_next;
        const char * m_type;
    } std_ll_t_node_t;

    typedef struct {
        std_ll_t_node_t * m_head;
        std_ll_t_node_t * m_last_node;
        int      m_size;
    } std_ll_t;

    void init_std_ll_t_node_t(std_ll_t_node_t * node, void * data, std_ll_t_node_t * next, const char * type);
    std_ll_t_node_t * create_std_ll_t_node_t(void * data, std_ll_t_node_t * next, const char * type); 
    void init_std_ll_t(std_ll_t * ll);
    int std_ll_t_insert_at_beginning(std_ll_t * ll, std_ll_t_node_t * data);
    int std_ll_t_insert_at_end(std_ll_t * ll, std_ll_t_node_t * data);
    int std_ll_t_remove(std_ll_t * ll, std_ll_t_node_t * remove_node);

#endif 

