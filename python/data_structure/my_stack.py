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
        self.__stack = []
        self.__size = stack_size
        self.__top = -1

    def is_empty(self):
        return self.__top == -1

    def is_full(self):
        return self.__top == self.__size - 1

    def clear(self):
        while self.__top != -1:
            del self.__stack[self.__top]
            self.__top -= 1

    def push(self, item):
        if self.is_full():
            print("Stack is Full.")
        else:
            self.__stack.append(item)
            self.__top += 1

    def pop(self):
        if self.is_empty():
            print("Stack is Empty.")
        else:
            tmp = self.__stack[self.__top]
            del self.__stack[self.__top]
            self.__top -= 1
            return tmp
            # return self.__stack.pop()

    def peek(self):
        if self.is_empty():
            print("Stack is Empty.")
        else:
            return self.__stack[self.__top]

    def print_stack(self):
        print(self.__stack)

    def size(self):
        return self.__size


class MyStack2(InnerStack):
    def __init__(self):
        self.__head = None
        self.__size = 0

    def is_empty(self):
        return self.__size == 0

    def clear(self):
        self.__head = None
        self.__size = 0

    def push(self, item):
        new_node = self.Node(item)
        new_node.next = self.__head
        self.__head = new_node
        self.__size += 1

    def pop(self):
        if self.is_empty():
            print("Stack is Empty.")
        else:
            tmp = self.__head.data
            self.__head = self.__head.next
            self.__size -= 1
            return tmp

    def peek(self):
        if self.is_empty():
            print("Stack is Empty.")
        else:
            return self.__head.data

    def size(self):
        return self.__size

    class Node:
        def __init__(self, item):
            self.data = item
            self.next = None


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
