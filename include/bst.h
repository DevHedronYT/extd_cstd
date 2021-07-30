/*class Node:
    def __init__(self, data):
        self.data = data 
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

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
