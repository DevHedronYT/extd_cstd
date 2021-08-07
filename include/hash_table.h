#ifndef _C_STD_HASHT

    #define _C_STD_HASHT
    
    #include <types.h>


    i32 hash_hash_table_t_node_t(const str key);

    typedef struct {
	    ret m_data;
        str m_key;
        i32 m_hash_val;
    } std_hash_table_t_node_t; 

    typedef struct {				
        std_hash_table_t_node_t ** m_data;
        i32  			           m_size;
    } std_hash_table_t;

    emp init_std_hash_table_t_node_t        (std_hash_table_t_node_t * node, ret data, str key);
    emp init_std_hash_table_t               (std_hash_table_t * table);
    emp add_pair_to_std_hash_table_t        (std_hash_table_t * table, std_hash_table_t_node_t * node);
    emp remove_elem_from_std_hash_table_t_at(std_hash_table_t * table, const str key);
    emp uninit_std_hash_table_t             (std_hash_table_t * table);

    std_hash_table_t_node_t * create_std_hash_table_t_node_t(ret data, str key);
    ret get_std_hash_table_t_node_t_data_value_at           (std_hash_table_t * table, const str key);
    

#endif


