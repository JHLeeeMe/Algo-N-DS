import unittest
from abc import ABC, abstractmethod


class InnerQueue(ABC):
    @abstractmethod
    def is_empty(self) -> bool: ...

    @abstractmethod
    def clear(self): ...

    @abstractmethod
    def enqueue(self, item): ...

    @abstractmethod
    def dequeue(self): ...

    @abstractmethod
    def peek(self): ...


class MyQueue(InnerQueue):
    def __init__(self):
        self.__front = None
        self.__rear = None
        self.__size = 0

    def is_empty(self):
        return self.__size == 0

    def clear(self):
        self.__front = self.__rear = None
        self.__size = 0

    def enqueue(self, item):
        new_node = self.Node(item)
        if self.is_empty():
            self.__front = new_node
        else:
            self.__rear.next = new_node
        self.__rear = new_node
        self.__size += 1

    def dequeue(self):
        if self.is_empty():
            print('Queue is Empty.')
        else:
            tmp = self.__front.data
            self.__front = self.__front.next
            self.__size -= 1
            return tmp
    
    def poll(self):
        return self.dequeue()

    def peek(self):
        if self.is_empty():
            print('Queue is Empty.')
        else:
            return self.__front.data

    def size(self) -> int:
        return self.__size

    class Node:
        def __init__(self, item):
            self.data = item
            self.next = None


class MyQueueTest(unittest.TestCase):
    def test_empty(self):
        my_queue = MyQueue()
        self.assertEqual(my_queue.size(), 0)
        self.assertTrue(my_queue.is_empty())
        self.assertEqual(my_queue.dequeue(), None)
        self.assertEqual(my_queue.poll(), None)
        self.assertEqual(my_queue.peek(), None)

    def test_all(self):
        my_queue = MyQueue()
        my_queue.enqueue(1)
        my_queue.enqueue(2)
        my_queue.enqueue(3)
        my_queue.enqueue(4)
        my_queue.enqueue(5)
        my_queue.enqueue(6)

        self.assertEqual(my_queue.size(), 6)
        self.assertFalse(my_queue.is_empty())
        self.assertEqual(my_queue.dequeue(), 1)
        self.assertEqual(my_queue.poll(), 2)
        self.assertEqual(my_queue.peek(), 3)
        self.assertEqual(my_queue.size(), 4)

        while my_queue.size() != 0:
            print('dequeue(): ' + str(my_queue.dequeue()))

        self.assertTrue(my_queue.size() == 0)

        my_queue.enqueue(3)
        my_queue.enqueue(4)
        my_queue.enqueue(5)
        self.assertEqual(my_queue.size(), 3)
        my_queue.clear()
        self.assertTrue(my_queue.is_empty())
        self.assertEqual(my_queue.size(), 0)
