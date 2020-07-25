import unittest
from abc import ABC, abstractmethod


class InnerBinarySearchTree(ABC):
    @abstractmethod
    def search(self): ...

    @abstractmethod
    def insert(self, item): ...

    @abstractmethod
    def delete(self, item): ...


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
        if self.__root is None:
            print('트리가 존재하지 않습니다.')
            return False

        if self.__root == item:
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

                self.__root.data = successor.data
                parent_of_successor.left = successor.right
        else:
            pass

        return True

    def __child_num(self, node) -> int:
        """Return child_node num of node"""
        if node.left is None and node.right is None:
            return 0
        elif node.left is not None and node.right is not None:
            return 2
        else:
            return 1

    def successor(self, node):
        parent = node
        node = node.right

        while node.left is not None:
            parent = node
            node = node.left

        return parent, node

    def search(self, item):
        pass


class BinarySearchTreeTest(unittest.TestCase):
    pass
