from abc import ABC, abstractmethod


class InnerQueue(ABC):
    @abstractmethod
    def is_empty(self) -> bool: ...

    @abstractmethod
    def clear(slef): ...

    @abstractmethod
    def enqueue(self, item): ...

    @abstractmethod
    def dequeue(self): ...

    @abstractmethod
    def peek(self): ...


class MyQueue(InnerQueue):
    def __init__(self):
        self.front = None
        self.rear = None
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def clear(self):
        self.front = self.rear = None
        self.size = 0

    def enqueue(self, item):
        new_node = self.Node(item)
        if self.is_empty():
            self.front = new_node
        else:
            self.rear.next = new_node
        self.rear = new_node
        self.size += 1

    def dequeue(self):
        if self.is_empty():
            print('Queue is Empty.')
        else:
            tmp = self.front.data
            self.front = self.front.next
            self.size -= 1
            return tmp

    def peek(self):
        if self.is_empty():
            print('Queue is Empty')
        else:
            return self.front.data

    class Node:
        def __init__(self, item):
            self.data = item
            self.next = None


if __name__ == '__main__':
    a = MyQueue()
    print(a.peek())
    print(a.dequeue())
    print(a.size())

    a.enqueue(1)
    a.enqueue(2)
    a.enqueue(3)
    a.enqueue(4)
    a.enqueue(4)
    a.enqueue(6)
    a.enqueue(7)
    print('peek(): ' + a.peek())

    while a.size() != 0:
        print('dequeue(): ' + a.dequeue())
        print('size(): ' + a.size())
