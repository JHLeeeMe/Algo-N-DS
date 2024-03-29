import unittest
from typing import Optional
from abc import ABC, abstractmethod


class Node:
    def __init__(self, item):
        self.data = item
        self.left = None
        self.right = None

    def __str__(self):
        return 'data: ' + str(self.data)


class InnerBinarySearchTree(ABC):
    @abstractmethod
    def insert(self, item: int) -> bool: ...

    @abstractmethod
    def delete(self, item: int) -> bool: ...

    @abstractmethod
    def search(self, item: int) -> Node: ...

    @abstractmethod
    def preorder(self) -> list: ...

    @abstractmethod
    def inorder(self) -> list: ...

    @abstractmethod
    def postorder(self) -> list: ...


class BinarySearchTree(InnerBinarySearchTree):
    def __init__(self):
        self._root = None
        self.preorder_lst = []
        self.inorder_lst = []
        self.postorder_lst = []

    # class Node:
    #     def __init__(self, item):
    #         self.data = item
    #         self.left = None
    #         self.right = None

    #     def __str__(self):
    #         return 'data: ' + str(self.data)

    def insert(self, item: int) -> Optional[bool]:
        """Insert item in BST

        Keyword arguments:
            item: int
        Return:
            bool
        """
        if self.search(item) is not None:
            print('중복 데이터 ' + str(item) + '(이)가 있으므로 insert하지 않음.')
            return False

        if self._root is None:
            self._root = Node(item)
            return True
        else:
            self._insert_node(self._root, item)

    def _insert_node(self, root, item):
        if root.data > item:
            if root.left is not None:
                return self._insert_node(root.left, item)
            else:
                root.left = Node(item)
        else:
            if root.right is not None:
                return self._insert_node(root.right, item)
            else:
                root.right = Node(item)

        return True

    def delete(self, item: int) -> bool:
        """Delete item in BST

        Keyword arguments:
            item: int
        Return:
            bool
        """
        if self._root is None:
            print('트리가 존재하지 않습니다.')
            return False

        if self._root.data == item:
            child_num = self._child_num(self._root)
            if child_num == 0:
                self._root = None
            elif child_num == 1:
                if self._root.left is None:
                    self._root = self._root.right
                else:
                    self._root = self._root.left
            else:
                tmp = self.successor(self._root)
                parent_of_successor = tmp[0]
                successor = tmp[1]

                if parent_of_successor != self._root:
                    self._root.data = successor.data
                    parent_of_successor.left = successor.right
                else:
                    self._root.data = successor.data
                    self._root.right = successor.right
            return True
        else:
            if self._root.data > item:
                return self._delete_node(self._root, self._root.left, item)
            else:
                return self._delete_node(self._root, self._root.right, item)

    def _delete_node(self, parent, curr, item):
        if curr is None:
            print('데이터가 존재하지 않습니다.')
            return False

        if curr.data == item:
            child_num = self._child_num(curr)
            if child_num == 0:
                if parent.left == curr:
                    parent.left = None
                else:
                    parent.right = None
            elif child_num == 1:
                if parent.left == curr:
                    if curr.left is None:
                        parent.left = curr.right
                    else:
                        parent.left = curr.left
                else:
                    if curr.left is None:
                        parent.right = curr.right
                    else:
                        parent.right = curr.left
            else:
                tmp = self.successor(curr)
                parent_of_successor = tmp[0]
                successor = tmp[1]

                curr.data = successor.data
                if parent_of_successor != curr:
                    parent_of_successor.left = successor.right
                else:
                    curr.right = successor.right
            return True
        else:
            if curr.data > item:
                return self._delete_node(curr, curr.left, item)
            else:
                return self._delete_node(curr, curr.right, item)

    def _child_num(self, node):
        """Returns child_node num of node"""
        if node.left is None and node.right is None:
            return 0
        elif node.left is not None and node.right is not None:
            return 2
        else:
            return 1

    def successor(self, node):
        """Returns (parent_of_successor, successor)"""
        parent = node
        node = node.right

        while node.left is not None:
            parent = node
            node = node.left

        return parent, node

    def search(self, item: int) -> Optional[Node]:
        """Search item in BST

        Keyword arguments:
            item: intk
            Node
        """
        if self._root is None:
            return None
        else:
            return self._search_node(self._root, item)

    def _search_node(self, curr, item):
        if curr.data == item:
            return curr

        if curr.data > item:
            if curr.left is not None:
                return self._search_node(curr.left, item)
        else:
            if curr.right is not None:
                return self._search_node(curr.right, item)
        return None

    def preorder(self):
        if self._root is not None:
            self._preorder_traversal(self._root)

    def _preorder_traversal(self, curr):
        self.preorder_lst.append(curr.data)

        if curr.left is not None:
            self._preorder_traversal(curr.left)
        if curr.right is not None:
            self._preorder_traversal(curr.right)

    def inorder(self):
        if self._root is not None:
            self._inorder_traversal(self._root)

    def _inorder_traversal(self, curr):
        if curr.left is not None:
            self._inorder_traversal(curr.left)

        self.inorder_lst.append(curr.data)

        if curr.right is not None:
            self._inorder_traversal(curr.right)

    def postorder(self):
        if self._root is not None:
            self._postorder_traversal(self._root)

    def _postorder_traversal(self, curr):
        if curr.left is not None:
            self._postorder_traversal(curr.left)
        if curr.right is not None:
            self._postorder_traversal(curr.right)

        self.postorder_lst.append(curr.data)


class BinarySearchTreeTest(unittest.TestCase):
    def setUp(self):
        #   10
        #    \
        #     50
        #     /\
        #   20  60
        #   /\
        # 17  30
        #     /
        #   25
        self.bst = BinarySearchTree()
        self.bst.insert(10)
        self.bst.insert(10)  # prints "중복 데이터 10 (이)가 있으므로 insert하지 않음."
        self.bst.insert(50)
        self.bst.insert(20)
        self.bst.insert(30)
        self.bst.insert(25)
        self.bst.insert(17)
        self.bst.insert(60)

    def test_all(self):
        # bst is ...
        #   10                           60
        #    \                           /
        #     50                       25
        #     /\                       /\
        #   20  60        ===>       17  30
        #   /\
        # 17  30
        #     /
        #   25
        self.assertEqual(self.bst._root.right.right.data, 60)
        self.bst.delete(60)
        self.assertEqual(self.bst._root.right.right, None)
        self.bst.insert(60)
        self.assertEqual(self.bst._root.right.right.data, 60)

        self.assertEqual(self.bst._root.right.left.data, 20)
        self.bst.delete(20)
        self.assertEqual(self.bst._root.right.left.data, 25)
        self.assertEqual(
            self.bst._root.right.left.right.data, 30
        )

        self.bst.delete(10)
        self.assertEqual(self.bst._root.data, 50)
        self.assertEqual(self.bst.search(50).left.data, 25)

        self.bst.delete(50)
        self.assertEqual(self.bst._root.data, 60)
        self.assertEqual(self.bst._root.left.data, 25)
        self.assertEqual(self.bst._root.left.left.data, 17)
        self.assertEqual(self.bst._root.left.right.data, 30)
        self.assertIsNone(self.bst._root.right)

        self.bst.delete(25)
        self.assertEqual(self.bst._root.data, 60)
        self.assertEqual(self.bst._root.left.data, 30)
        self.assertEqual(self.bst._root.left.left.data, 17)
        self.assertIsNone(self.bst._root.left.right)
        self.assertIsNone(self.bst._root.right)

    def test_traversal(self):
        self.bst.preorder()
        self.assertEqual(self.bst.preorder_lst, [10, 50, 20, 17, 30, 25, 60])

        self.bst.inorder()
        self.assertEqual(self.bst.inorder_lst, [10, 17, 20, 25, 30, 50, 60])

        self.bst.postorder()
        self.assertEqual(self.bst.postorder_lst, [17, 25, 30, 20, 60, 50, 10])
