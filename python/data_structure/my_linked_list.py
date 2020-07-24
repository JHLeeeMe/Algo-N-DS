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
    def print_all(self): ...


class MyLinkedList(InnerLinkedList):
    def __init__(self):
        self.__head = None
        self.__size = 0

    class Node:
        def __init__(self, item):
            self.data = item
            self.next = None

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
            while curr.next is not None:
                curr = curr.next
            curr.next = new_node
        self.__size += 1

    def add_into_index(self, idx, item):
        if idx < 0 or idx > self.__size:
            raise IndexError('idx arg must be within 0 ~ '
                             + str(self.__size))

        new_node = self.Node(item)
        if idx == 0:
            new_node.next = self.__head
            self.__head = new_node
        else:
            before_node = self.__node(idx - 1)
            new_node.next = before_node.next
            before_node.next = new_node
        self.__size += 1

    def remove(self):
        return self.__remove_first()

    def __remove_first(self):
        if self.__size == 0:
            print('List is Empty.')
            return None

        tmp = self.__head.data
        self.__head = self.__head.next
        self.__size -= 1
        return tmp

    def remove_by_index(self, idx):
        if idx < 0 or idx >= self.__size:
            raise IndexError('idx arg must be within 0 ~ '
                             + str(self.__size - 1))

        if idx == 0:
            return self.__remove_first()

        before_node = self.__node(idx - 1)
        tmp = before_node.next.data
        before_node.next = before_node.next.next
        self.__size -= 1
        return tmp

    def remove_by_item(self, item):
        idx = self.__index_of(item)
        if idx != -1:
            return self.remove_by_index(idx)
        return None

    def __index_of(self, item):
        curr = self.__head
        idx = 0
        while curr is not None:
            if curr.data == item:
                return idx
            curr = curr.next
            idx += 1
        print('data ' + str(item) + ' is not in linkedlist')
        return -1

    def __node(self, idx):
        if not isinstance(idx, int):
            raise TypeError('idx arg must be int type')

        curr = self.__head
        for i in range(idx):
            curr = curr.next
        return curr

    def size(self):
        return self.__size

    def print_all(self):
        tmp = []
        curr = self.__head
        while curr is not None:
            tmp.append(curr.data)
            curr = curr.next
        print(tmp)

    def __iter__(self):
        """Returns the Iterator object."""
        return self.MyIterator(self.__head)

    class MyIterator:
        """Iterator class"""
        def __init__(self, head):
            self.__curr = head

        def __next__(self):
            """Returns the next value from list"""
            if self.__curr is None:
                raise StopIteration

            tmp = self.__curr.data
            self.__curr = self.__curr.next
            return tmp


class MyLinkedListTest(unittest.TestCase):
    def setUp(self):
        self.my_list = MyLinkedList()

    def test_empty(self):
        print()
        print('################')
        print('# test_empty() #')
        print('################')

        self.assertEqual(self.my_list.remove(), None)
        self.assertEqual(self.my_list.remove_by_item('aaaa'), None)

        with self.assertRaises(IndexError):
            self.my_list.remove_by_index(1)

        with self.assertRaises(TypeError):
            self.my_list._MyLinkedList__node('aaa')

    def test_all(self):
        print()
        print('##############')
        print('# test_all() #')
        print('##############')

        self.my_list.add(1)
        self.my_list.add(2)
        self.my_list.add_into_index(0, 3)
        self.my_list.print_all()

        with self.assertRaises(IndexError):
            self.my_list.add_into_index(-1, 123)

        with self.assertRaises(IndexError):
            self.my_list.add_into_index(1123123, 123)

        self.my_list.add(12345)
        self.assertEqual(self.my_list.size(), 4)
        self.my_list.print_all()
        self.assertEqual(self.my_list.remove_by_item(12345), 12345)
        self.my_list.print_all()

        with self.assertRaises(IndexError):
            self.my_list.remove_by_index(3)

    def test_iterator(self):
        print()
        print('###################')
        print('# test_iterator() #')
        print('###################')

        self.my_list.add(1)
        self.my_list.add(2)
        self.my_list.add(3)
        self.my_list.add(4)
        self.my_list.add(5)
        self.my_list.print_all()                      # prints [1, 2, 3, 4, 5]

        for item in self.my_list:
            print(item)
