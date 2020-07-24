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
        def __init__(self):
            self.data = None
            self.left = None
            self.right = None

    def insert(self, item):
        pass

    def delete(self, item):
        pass

    def search(self, item):
        pass


class BinarySearchTreeTest(unittest.TestCase):
    pass
