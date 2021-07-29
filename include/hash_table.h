#ifndef _C_STD_HASHT

    #define _C_STD_HASHT
   
     typedef struct {
	void *  m_data;
	char *  m_key;
	int     m_hash_val;
    } std_hash_table_t_node_t; 

    typedef struct {				
	std_hash_table_t_node_t ** m_data;
	int  			   m_size;
    } std_hash_table_t;


    int hash_hash_table_t_node_t(const char * key);
    void init_std_hash_table_t_node_t(std_hash_table_t_node_t * node, void * data, char * key);
    std_hash_table_t_node_t * create_std_hash_table_t_node_t(void * data, char * key);
    void * get_std_hash_table_t_node_t_data_value_at(std_hash_table_t * table, const char * key);
    void init_std_hash_table_t(std_hash_table_t * table);
    void add_pair_to_std_hash_table_t(std_hash_table_t * table, std_hash_table_t_node_t * node);
    void remove_elem_from_std_hash_table_t_at(std_hash_table_t * table, const char * key);
    void uninit_std_hash_table_t(std_hash_table_t * table);

    

#endif


