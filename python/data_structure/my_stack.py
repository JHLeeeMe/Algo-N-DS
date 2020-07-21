from abc import ABC, abstractmethod


class InnerStack(ABC):
    @abstractmethod
    def is_empty(self) -> bool: ...

    @abstractmethod
    def clear(slef): ...

    @abstractmethod
    def push(self, item): ...

    @abstractmethod
    def pop(self): ...

    @abstractmethod
    def peek(self): ...


class MyStack(InnerStack):
    def __init__(self, stack_size: int = 10):
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
        self.head = None
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def clear(self):
        self.head = None
        self.size = 0

    def push(self, item):
        new_node = self.Node(item)
        new_node.next = self.head
        self.head = new_node
        self.size += 1

    def pop(self):
        if self.is_empty():
            print("Stack is Empty")
        else:
            tmp = self.head.data
            self.head = self.head.next
            self.size -= 1
            return tmp

    def peek(self):
        if self.is_empty():
            print("Stack is Empty")
        else:
            return self.head.data

    def get_size(self):
        if self.is_empty():
            print("Stack is Empty")
        else:
            return self.size

    class Node:
        def __init__(self, item):
            self.data = item
            self.next = None


if __name__ == '__main__':
    a = MyStack()
    print(a.size())
    a.print_stack()

    a.push(1)
    a.push(2)
    a.push(3)
    a.push(4)
    a.push(5)
    a.push(6)
    a.push(7)
    a.push(8)
    a.push(9)
    a.push("asdf")

    a.print_stack()
    print(a.pop())
    a.print_stack()
    print(a.pop())
    a.print_stack()
    print(a.pop())
    a.print_stack()
    print(a.pop())
    a.print_stack()
    print(a.pop())
    a.print_stack()
    print(a.pop())
    a.print_stack()
    print(a.pop())
    a.print_stack()
    print(a.pop())
    a.print_stack()
    print(a.pop())
    a.print_stack()
    print(a.pop())
    a.print_stack()
    print(a.pop())
    a.print_stack()

    print('===================================================')

    c = MyStack2()

    c.pop()
    c.peek()

    c.push(1)
    c.push(2)
    c.push(3)
    c.push(4)
    c.push(5)
    c.push(6)
    c.push(7)
    c.push(8)

    while not c.is_empty():
        print(c.pop())

    c.push(2)
    c.push(14)
    c.push(60)
    print(c.peek())
    print(c.get_size())

    c.clear()
    print(c.get_size())
