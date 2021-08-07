#ifndef _C_STD_BST

    #define _C_STD_BST
   
    #include <types.h>

    typedef struct _std_bst_t_node_t {	
	    i32                        m_data;
        struct _std_bst_t_node_t * m_left;
        struct _std_bst_t_node_t * m_right;
    } std_bst_t_node_t;

    typedef struct {	
        std_bst_t_node_t * m_root;
        i32         	   m_size;
    } std_bst_t;

    emp init_std_bst_t_node_t(std_bst_t_node_t * node, i32 data, std_bst_t_node_t * left, std_bst_t_node_t * right);
    emp init_std_bst_t       (std_bst_t * bst);
    emp std_bst_t_insert     (std_bst_t * bst, std_bst_t_node_t * node);
    
    std_bst_t_node_t * create_std_bst_t_node_t(i32 data, std_bst_t_node_t * left, std_bst_t_node_t * right); 
    i32 std_bst_t_search_for                  (std_bst_t * bst, std_bst_t_node_t * node);

#endif
