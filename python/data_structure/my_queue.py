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
        self._front = None
        self._rear = None
        self._size = 0

    class Node:
        def __init__(self, item):
            self.data = item
            self.next = None

    def is_empty(self) -> bool:
        return self._size == 0

    def clear(self):
        self._front = self._rear = None
        self._size = 0

    def enqueue(self, item):
        new_node = self.Node(item)
        if self.is_empty():
            self._front = new_node
        else:
            self._rear.next = new_node
        self._rear = new_node
        self._size += 1

    def dequeue(self):
        if self.is_empty():
            print('Queue is Empty.')
        else:
            tmp = self._front.data
            self._front = self._front.next
            self._size -= 1
            return tmp

    def poll(self):
        return self.dequeue()

    def peek(self):
        if self.is_empty():
            print('Queue is Empty.')
        else:
            return self._front.data

    def size(self) -> int:
        return self._size


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
