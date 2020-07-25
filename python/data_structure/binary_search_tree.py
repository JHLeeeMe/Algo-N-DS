import unittest
from abc import ABC, abstractmethod


class InnerBinarySearchTree(ABC):
    @abstractmethod
    def insert(self, item: int) -> bool: ...

    @abstractmethod
    def delete(self, item: int) -> bool: ...

    @abstractmethod
    def search(self, item: int) -> int: ...


class BinarySearchTree(InnerBinarySearchTree):
    def __init__(self):
        self.__root = None

    class Node:
        def __init__(self, item):
            self.data = item
            self.left = None
            self.right = None

    def insert(self, item: int) -> bool:
        """Insert item in BST

        Keyword arguments:
            item: int
        Return:
            bool
        """
        if self.search(item) is not None:
            print('중복 데이터 ' + item + '(이)가 있으므로 insert하지 않음.')
            return False

        if self.__root is None:
            self.__root = self.Node(item)
            return True
        else:
            self.__insert_node(self.__root, item)

    def __insert_node(self, root, item):
        if root.data > item:
            if root.left is not None:
                return self.__insert_node(root.left, item)
            else:
                root.left = self.Node(item)
        else:
            if root.right is not None:
                return self.__insert_node(root.right, item)
            else:
                root.right = self.Node(item)

        return True

    def delete(self, item: int) -> bool:
        """Delete item in BST

        Keyword arguments:
            item: int
        Return:
            bool
        """
        if self.__root is None:
            print('트리가 존재하지 않습니다.')
            return False

        if self.__root.data == item:
            child_num = self.__child_num(self.__root)
            if child_num == 0:
                self.__root = None
            elif child_num == 1:
                if self.__root.left is None:
                    self.__root = self.__root.right
                else:
                    self.__root = self.__root.left
            else:
                tmp = self.successor(self.__root)
                parent_of_successor = tmp[0]
                successor = tmp[1]

                if parent_of_successor != self.__root:
                    self.__root.data = successor.data
                    parent_of_successor.left = successor.right
                else:
                    self.__root.data = successor.data
                    self.__root.right = successor.right
            return True
        else:
            if self.__root.data > item:
                return self.__delete_node(self.__root, self.__root.left, item)
            else:
                return self.__delete_node(self.__root, self.__root.right, item)

    def __delete_node(self, parent, curr, item):
        if curr is None:
            print('데이터가 존재하지 않습니다.')
            return False

        if curr.data == item:
            child_num = self.__child_num(curr)
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
                return self.__delete_node(curr, curr.left, item)
            else:
                return self.__delete_node(curr, curr.right, item)

    def __child_num(self, node):
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

    def search(self, item: int) -> int:
        pass


class BinarySearchTreeTest(unittest.TestCase):
    pass
