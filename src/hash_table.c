#include <hash_table.h>
#include <stdlib.h>
#include <stdio.h>

int g_size = 1000;

int hash_hash_table_t_node_t(const char * key) {
    int num = 0;
    int i = 0;
   
    // Good hash function should probably make the best
    // use of the int value of the chars in the key
    while (key[i] != '\0') {
	//num += i + key[i] * (2^i);
	//num += i + key[i] * (i^2);
	//num += i + key[i] * (i^key[i]);
	num += i + key[i];
	i++;
    }

    return num % g_size;
}


void init_std_hash_table_t_node_t(std_hash_table_t_node_t * node, void * data, char * key) {
    node -> m_data = data;
    node -> m_key  = key;
    node -> m_hash_val = hash_hash_table_t_node_t(key); 
}

std_hash_table_t_node_t * create_std_hash_table_t_node_t(void * data, char * key) {
    std_hash_table_t_node_t * node = malloc(sizeof(std_hash_table_t_node_t));
    
    node -> m_data = data;
    node -> m_key  = key;
    node -> m_hash_val = hash_hash_table_t_node_t(key); 

    return node;
}


void init_std_hash_table_t(std_hash_table_t * table) {
    table -> m_data = malloc(sizeof(std_hash_table_t_node_t) * 1001);
    for (int i = 0; i < 1001; i++) {
	table -> m_data[i] = NULL;
    }
    table -> m_size = 1000; 
    g_size += 0;
}
    
void add_pair_to_std_hash_table_t(std_hash_table_t * table, std_hash_table_t_node_t * node) {
    if (table -> m_size >= node -> m_hash_val) {
	table -> m_data[node -> m_hash_val] = node;
    }
    
    if (table -> m_size <= node -> m_hash_val) {
	table -> m_data = realloc(table -> m_data, table -> m_size + node -> m_hash_val);
	table -> m_size = table -> m_size + node -> m_hash_val - 1;
	g_size = table -> m_size;
    }

}

void remove_elem_from_std_hash_table_t_at(std_hash_table_t * table, const char * key) {
    if (table -> m_data[hash_hash_table_t_node_t(key)])
	table -> m_data[hash_hash_table_t_node_t(key)] = NULL;     
}

void uninit_std_hash_table_t(std_hash_table_t * table) {
    free(table);
}


void * get_std_hash_table_t_node_t_data_value_at(std_hash_table_t * table, const char * key) {
    if (!table -> m_data[hash_hash_table_t_node_t(key)])
	return 0x0;


    return table -> m_data[hash_hash_table_t_node_t(key)] -> m_data;
}

