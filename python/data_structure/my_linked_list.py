import unittest
from abc import ABC, abstractmethod


class InnerLinkedList(ABC):
    @abstractmethod
    def is_empty(self) -> bool: ...
    @abstractmethod
    def add(self, item): ...
    @abstractmethod
    def remove(self): ...
    @abstractmethod
    def remove_item(self, item): ...
    @abstractmethod
    def __index_of(self, item) -> int: ...
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
        self.__add_last(item)

    def __add_last(self, item):
        new_node = self.Node(item)
        if self.__size == 0:
            self.__head = new_node
        else:
            curr = self.__head
            while curr.__next is not None:
                curr = curr.__next
            curr.__next = new_node
        self.__size += 1

    def add_into_index(self, idx, item):
        if idx < 0 or idx > self.__size:
            raise IndexError('idx arg must be within 0 ~ '
                             + str(self.__size))

        new_node = self.Node(item)
        if idx == 0:
            new_node.__next = self.__head
            self.__head = new_node
        else:
            before_node = self.__node(idx - 1)
            new_node.__next = before_node.__next
            before_node.__next = new_node
        self.__size += 1

    def remove(self):
        return self.__remove_first()

    def __remove_first(self):
        if self.__size == 0:
            return None

        tmp = self.__head.__data
        self.__head = self.__head.__next
        self.__size -= 1
        return tmp

    def remove_by_index(self, idx):
        if idx < 0 or idx >= self.__size:
            raise IndexError('idx arg must be within 0 ~ '
                             + str(self.__size - 1))

        if idx == 0:
            return self.__remove_first()

        before_node = self.__node(idx - 1)
        tmp = before_node.__next.__data
        before_node.__next = before_node.__next.__next
        self.__size -= 1
        return tmp

    def remove_by_item(self, item):
        idx = self.__idex_of(item)
        if idx != -1:
            return self.remove_by_index(idx)
        return None

    def __index_of(self, item):
        curr = self.__head
        idx = 0
        while curr is not None:
            if curr.__data == item:
                return idx
            curr = curr.__next
            idx += 1
        print('data ' + str(item) + 'is not in linkedlist')
        return -1

    def __node(self, idx):
        curr = self.__head
        for i in range(idx):
            curr = curr.__next
        return curr

    def size(self):
        return self.__size

    def print_list(self):
        tmp = []
        curr = self.__head
        while curr is not None:
            tmp.append(curr.__data)
            curr = curr.__next
        print(tmp)


class MyLinkedListTest(unittest.TestCase):
    pass
