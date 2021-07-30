/*
    def _InsertRecursive(self, data, node):
        if data["id"] < node.data["id"]:
            if node.left is None:
                node.left = Node(data)

            else:
                self._InsertRecursive(data, node.left)

        elif data["id"] > node.data["id"]:
            if node.right is None:
                node.right = Node(data)

            else:
                self._InsertRecursive(data, node.right)

        else:
            return

    def Insert(self, data):
        if self.root is None:
            self.root = Node(data)

        else:
           self._InsertRecursive(data, self.root)

    def _SearchRecursive(self, blogPostID, node):
        if blogPostID == node.data["id"]:
            return node.data

        if blogPostID < node.data["id"] and node.left is not None:
            if blogPostID == node.left.data["id"]:
                return node.left.data
            
            return self._SearchRecursive(blogPostID, node.left)

        if blogPostID > node.data["id"] and node.right is not None:
            if blogPostID == node.right.data["id"]:
                return node.right.data

            return self._SearchRecursive(blogPostID, node.right)

        return False

    def Search(self, blogPostID):
        blogPostID = int(blogPostID)
        if self.root is None:
            return False

        return self._SearchRecursive(blogPostID, self.root)
*/ 

#ifndef _C_STD_BST

    #define _C_STD_BST
    
    typedef struct _std_bst_t_node_t {	
	void * m_data;
	const char * m_type;
	_std_bst_t_node_t * m_left;
	_std_bst_t_node_t * m_right;
    } std_bst_t_node_t;

    typedef struct {	
	std_bst_t_node_t * m_root;
	int      	   m_size;
    } std_bst_t;

    void init_std_bst_t_node_t(std_bst_t_node_t * node, void * data, std_bst_t_node_t * left, std_bst_t_node_t * right, const char * type);
    std_bst_t_node_t * create_std_bst_t_node_t(void * data, std_bst_t_node_t * left, std_bst_t_node_t * right, const char * type); 
    void init_std_bst_t(std_bst_t * bst);
    void std_bst_t_insert__recursive(std_bst_t * bst, std_bst_t_node_t * node);
    void std_bst_t_insert(std_bst_t * bst, std_bst_t_node_t * node);
    void * std_bst_t_search_for(std_bst_t * bst, std_bst_t_node_t * node);
    void remove_from_std_bst_t(std_bst_t * bst, std_bst_t_node_t * node);


#endif
