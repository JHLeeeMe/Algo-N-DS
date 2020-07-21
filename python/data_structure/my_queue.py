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
    def __init__(self, item):
        self.front = None
        self.rear = None
        self.size = 0

    def is_empty(self):
        pass

    def clear(self):
        pass

    def enqueue(self, item):
        pass

    def dequeue(self):
        pass

    def peek(self):
        pass

    class Node:
        def __init__(self, item):
            self.data = item
            self.next = None


if __name__ == '__main__':
    pass
