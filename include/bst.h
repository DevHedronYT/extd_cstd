#ifndef _C_STD_BST

    #define _C_STD_BST
    
    typedef struct _std_bst_t_node_t {	
	int m_data;
        struct _std_bst_t_node_t * m_left;
        struct _std_bst_t_node_t * m_right;
    } std_bst_t_node_t;

    typedef struct {	
        std_bst_t_node_t * m_root;
        int      	   m_size;
    } std_bst_t;

    void init_std_bst_t_node_t(std_bst_t_node_t * node, int data, std_bst_t_node_t * left, std_bst_t_node_t * right);
    std_bst_t_node_t * create_std_bst_t_node_t(int data, std_bst_t_node_t * left, std_bst_t_node_t * right); 
    void init_std_bst_t(std_bst_t * bst);
    void std_bst_t_insert__recursive(std_bst_t_node_t * node, std_bst_t_node_t * r_node);
    void std_bst_t_insert(std_bst_t * bst, std_bst_t_node_t * node);
    int std_bst_search_for__recursive(std_bst_t_node_t * node, std_bst_t_node_t * r_node); 
    int std_bst_t_search_for(std_bst_t * bst, std_bst_t_node_t * node);


#endif
