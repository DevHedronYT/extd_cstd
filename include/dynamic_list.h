#ifndef _C_STD_LIST

    #define _C_STD_LIST
    
    typedef struct {
	int  m_size;
	void ** m_data;
	int  m_r_size;
    } dynamic_list_t;

    void init_dynamic_list(dynamic_list_t * list);
    void add_elem_to_dynamic_list(dynamic_list_t * list, void * item);
    void remove_elem_from_dynamic_list(dynamic_list_t * list, int index);
    void uninit_dynamic_list(dynamic_list_t * list);

#endif
