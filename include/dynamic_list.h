#ifndef _C_STD_LIST

    #define _C_STD_LIST
   
    typedef struct {
        void * m_data;
        const char * m_type;
    } std_dynamic_list_t_node_t;

    typedef struct {
        int  m_size;
        void ** m_data;
        int  m_r_size;
    } std_dynamic_list_t;

    void init_std_dynamic_list_t_node_t(std_dynamic_list_t_node_t * node, void * data, const char * type);
    std_dynamic_list_t_node_t * create_std_dynamic_list_t_node_t(void * data, const char * type);
    void * get_std_dynamic_list_t_node_t_data_value_at(std_dynamic_list_t * list, int index);
    void init_std_dynamic_list_t(std_dynamic_list_t * list);
    void add_elem_to_std_dynamic_list_t(std_dynamic_list_t * list, std_dynamic_list_t_node_t * node);
    void remove_elem_from_std_dynamic_list_t_at(std_dynamic_list_t * list, int index);
    void remove_elem_from_std_dynamic_list_t(std_dynamic_list_t * list, std_dynamic_list_t_node_t * node);
    void uninit_std_dynamic_list_t(std_dynamic_list_t * list);

#endif
