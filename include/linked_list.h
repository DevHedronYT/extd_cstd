#ifndef _C_STD_LLIST

    #define _C_STD_LLIST

    typedef struct _node_t {
	void * m_data;
	struct _node_t * m_next;
	const char * m_type;
    } node_t;

    typedef struct {
	node_t * m_head;
	node_t * m_last_node;
	int      m_size;
    } ll_t;

    void    init_node_t(node_t * node, void * data, node_t * next);
    void    init_ll_t(ll_t * ll);
    void ** ll_t_to_arr(ll_t * ll);
    int     ll_t_insert_at_beginning(ll_t * ll, node_t * data);
    int     ll_t_insert_at_end(ll_t * ll, node_t * data);
    node_t  ll_t_get_user_by_id(ll_t * ll, int index);
    int     ll_t_remove(ll_t * ll, node_t * remove_node);

#endif 

