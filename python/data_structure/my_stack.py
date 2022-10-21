import unittest
from abc import ABC, abstractmethod


class InnerStack(ABC):
    @abstractmethod
    def is_empty(self) -> bool: ...

    @abstractmethod
    def clear(self): ...

    @abstractmethod
    def push(self, item): ...

    @abstractmethod
    def pop(self): ...

    @abstractmethod
    def peek(self): ...


class MyStack(InnerStack):
    def __init__(self, stack_size: int = 10):
        if not isinstance(stack_size, int):
            raise TypeError('stack_size arg must be int type')
        if stack_size <= 0:
            raise IndexError('Stack size must be greater than 0')
        self._stack = []
        self._size = stack_size
        self._top = -1

    def is_empty(self) -> bool:
        return self._top == -1

    def is_full(self) -> bool:
        return self._top == self._size - 1

    def clear(self):
        while self._top != -1:
            del self._stack[self._top]
            self._top -= 1

    def push(self, item):
        if self.is_full():
            print("Stack is Full.")
        else:
            self._stack.append(item)
            self._top += 1

    def pop(self):
        if self.is_empty():
            print("Stack is Empty.")
        else:
            tmp = self._stack[self._top]
            del self._stack[self._top]
            self._top -= 1
            return tmp
            # return self._stack.pop()

    def peek(self):
        if self.is_empty():
            print("Stack is Empty.")
        else:
            return self._stack[self._top]

    def print_stack(self):
        print(self._stack)

    def size(self) -> int:
        return self._size


class MyStack2(InnerStack):
    def __init__(self):
        self._head = None
        self._size = 0

    class Node:
        def __init__(self, item):
            self.data = item
            self.next = None

    def is_empty(self) -> bool:
        return self._size == 0

    def clear(self):
        self._head = None
        self._size = 0

    def push(self, item):
        new_node = self.Node(item)
        new_node.next = self._head
        self._head = new_node
        self._size += 1

    def pop(self):
        if self.is_empty():
            print("Stack is Empty.")
        else:
            tmp = self._head.data
            self._head = self._head.next
            self._size -= 1
            return tmp

    def peek(self):
        if self.is_empty():
            print("Stack is Empty.")
        else:
            return self._head.data

    def size(self) -> int:
        return self._size


class MyStackTest(unittest.TestCase):
    def test_empty(self):
        my_stack = MyStack()
        self.assertEqual(my_stack.size(), 10)
        self.assertTrue(my_stack.is_empty())
        self.assertEqual(my_stack.pop(), None)
        self.assertEqual(my_stack.peek(), None)

        my_stack2 = MyStack2()
        self.assertEqual(my_stack2.size(), 0)
        self.assertTrue(my_stack2.is_empty())
        self.assertEqual(my_stack2.pop(), None)
        self.assertEqual(my_stack2.peek(), None)

    def test_all_my_stack(self):
        my_stack = MyStack()
        for i in range(1, 11):
            my_stack.push(i)

        self.assertIsNone(my_stack.push(11))  # prints 'Stack is Full.'
        self.assertTrue(my_stack.is_full())
        self.assertFalse(my_stack.is_empty())
        self.assertEqual(my_stack.pop(), 10)
        self.assertFalse(my_stack.is_full())

        my_stack.clear()
        self.assertTrue(my_stack.is_empty())
        self.assertIsNone(my_stack.pop())

        my_stack = MyStack(3)
        for i in range(1, 4):
            my_stack.push(i)

        self.assertEqual(my_stack.size(), 3)
        self.assertTrue(my_stack.is_full())
        self.assertEqual(my_stack.peek(), 3)

        with self.assertRaises(IndexError):
            MyStack(-1)

        with self.assertRaises(TypeError):
            MyStack('aaaa')

    def test_all_my_stack2(self):
        my_stack2 = MyStack2()
        for i in range(1, 11):
            my_stack2.push(i)

        self.assertIsNone(my_stack2.push(11))
        self.assertFalse(my_stack2.is_empty())
        self.assertEqual(my_stack2.pop(), 11)

        my_stack2.clear()
        self.assertTrue(my_stack2.is_empty())
        self.assertIsNone(my_stack2.pop())
