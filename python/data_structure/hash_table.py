import unittest
from abc import ABC, abstractmethod


class InnerHashTable(ABC):
    @abstractmethod
    def hash_function(self, key) -> int: ...

    @abstractmethod
    def put(self, key, value) -> bool: ...

    @abstractmethod
    def get(self, key) -> str: ...

    @abstractmethod
    def delete(self, key) -> bool: ...

    @abstractmethod
    def print_all(self): ...


class HashTable(InnerHashTable):
    def __init__(self, capacity: int = 10):
        self.capacity = capacity
        self.lst = [None for i in range(capacity)]

    class Node:
        def __init__(self, key, value):
            self.key = key
            self.value = value
            self.next = None

    def hash_function(self, key: int) -> int:
        hash_idx = hash(key)
        return hash_idx % self.capacity

    def put(self, key: int, value: str) -> bool:
        hash_idx = self.hash_function(key)
        curr = self.lst[hash_idx]

        new_node = self.Node(key, value)
        if self.lst[hash_idx] is None:
            self.lst[hash_idx] = new_node
            return True
        else:
            while curr is not None:
                if curr.key == key:
                    curr.value = value
                    return True
                curr = curr.next

        return False

    def get(self, key):
        ...

    def delete(self, key):
        ...

    def print_all(self):
        ...


class HashTableTest(unittest.TestCase):
    def setUp(self):
        self.H = HashTable()

    def test_all(self):
        key = 100
        print(self.H.hash_function(key))

        self.H.put(123, "Hello HashTable")
        self.H.put(123, "test")
        print(self.H.lst[self.H.hash_function(123)].value)
