/*

*/ 

#include <bst.h>
#include <stdlib.h>

emp init_std_bst_t_node_t(std_bst_t_node_t * node, i32 data, std_bst_t_node_t * left, std_bst_t_node_t * right) {
    node -> m_data = data;
    node -> m_left = left;
    node -> m_right = right;
}

emp init_std_bst_t(std_bst_t * bst) {
    bst -> m_root = NULL;
    bst -> m_size = 0;
}

emp std_bst_t_insert__recursive(std_bst_t_node_t * node, std_bst_t_node_t * r_node) {
    if (node -> m_data < r_node -> m_data) {
        if (r_node -> m_left == NULL) {
            r_node -> m_left = node;
        }

        else {
            std_bst_t_insert__recursive(node, r_node -> m_left);
        }
    }

    else if (node -> m_data > r_node -> m_data) {
        if (r_node -> m_right == NULL) {
            r_node -> m_right = node;
        }

        else {
            std_bst_t_insert__recursive(node, r_node -> m_right);
        }
    }

    else {
	    return;
    }
}

emp std_bst_t_insert(std_bst_t * bst, std_bst_t_node_t * node) {
    if (bst -> m_root == NULL) {
        bst -> m_root = node;
        return;
    }

    std_bst_t_insert__recursive(node, bst -> m_root);
    bst -> m_size += 1;
}

i32 std_bst_search_for__recursive(std_bst_t_node_t * node, std_bst_t_node_t * r_node) {
    if (node -> m_data == r_node -> m_data) return r_node -> m_data;
    if (node -> m_data < r_node -> m_data && r_node != NULL) {
        if (node -> m_data == r_node -> m_left -> m_data) {
            return r_node -> m_left -> m_data;
        }

        return std_bst_search_for__recursive(node, r_node -> m_left);
    }

    if (node -> m_data > r_node -> m_data && r_node != NULL) {
        if (node -> m_data == r_node -> m_right -> m_data) {
            return r_node -> m_right -> m_data;
        }

        return std_bst_search_for__recursive(node, r_node -> m_right);
    }

    return -1;
}

i32 std_bst_t_search_for(std_bst_t * bst, std_bst_t_node_t * node) {
    if (bst -> m_root == NULL) return -1;
    return std_bst_search_for__recursive(node, bst -> m_root);
}

std_bst_t_node_t * create_std_bst_t_node_t(i32 data, std_bst_t_node_t * left, std_bst_t_node_t * right) {
    std_bst_t_node_t * node = malloc(sizeof(std_bst_t_node_t));
    node -> m_data = data;
    node -> m_left = left;
    node -> m_right = right;

    return node;
}


