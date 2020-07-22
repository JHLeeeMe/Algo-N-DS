import unittest
from abc import ABC, abstractmethod


class InnerLinkedList(ABC):
    @abstractmethod
    def is_empty(self) -> bool: ...
    @abstractmethod
    def add(self, item): ...
    @abstractmethod
    def remove_item(self, item): ...
    @abstractmethod
    def index_of(self, item) -> int: ...
    @abstractmethod
    def print_list(self): ...


class MyLinkedList(InnerLinkedList):
    def __init__(self):
        self.__head = None
        self.__size = 0

    class Node:
        def __init__(self, item):
            self.__data = item
            self.__next = None

    def is_empty(self):
        return self.__size == 0

    def add(self, item):
        pass

    def remove_item(self, item):
        pass

    def index_of(self, item):
        pass

    def size(self):
        return self.__size

    def print_list(self):
        pass


class MyLinkedListTest(unittest.TestCase):
    pass
