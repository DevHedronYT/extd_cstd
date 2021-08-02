#include <bst.h>
#include <util.h>

int main(void) {
    std_bst_t bst;
    
    init_std_bst_t(&bst);

    std_bst_t_insert(&bst, create_std_bst_t_node_t(10, create_std_bst_t_node_t(5, NULL, NULL), create_std_bst_t_node_t(49, NULL, NULL)));
    std_bst_t_insert(&bst, create_std_bst_t_node_t(100, NULL, NULL));

}

