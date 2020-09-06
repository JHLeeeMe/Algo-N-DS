import unittest
from abc import ABC, abstractmethod


class InnerHashTable(ABC):
    @abstractmethod
    def hash(self, key) -> int: ...

    @abstractmethod
    def put(self, key, value) -> bool: ...

    @abstractmethod
    def get(self, key) -> str: ...

    @abstractmethod
    def delete(self, key) -> bool: ...

    @abstractmethod
    def print_all(self): ...


class HashTable(InnerHashTable):
    def __init__(self):
        ...

    class Node:
        def __init__(self, capacity):
            ...


class HashTableTest(unittest.TestCase):
    def setUp(self):
        ...

    def test_all(self):
        ...
