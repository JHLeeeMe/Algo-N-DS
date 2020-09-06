import unittest
from abc import ABC, abstractmethod


class InnerHashTable(ABC):
    @abstractmethod
    def hash_function(self, key) -> int: ...

    @abstractmethod
    def put(self, key, value) -> bool: ...

    @abstractmethod
    def get(self, key) -> object: ...

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

    def hash_function(self, key: object) -> int:
        """Return hash code of key

        Keyword arguments:
            key: object
        Returns:
            : int
        """
        try:
            if key is None:
                raise Exception('key is None.')

            hash_idx = hash(key)
        except Exception as e:
            print('Exception: ', e)

        return hash_idx % self.capacity

    def put(self, key: object, value: object) -> bool:
        """Put key, value pair

        Keyword arguments:
            key: object
            value: object
        Returns:
            : bool
        """
        hash_idx = self.hash_function(key)
        new_node = self.Node(key, value)

        if self.lst[hash_idx] is None:
            self.lst[hash_idx] = new_node
        else:
            if self.lst[hash_idx].key == key:
                self.lst[hash_idx].value = value
                return True

            prev = self.lst[hash_idx]
            curr = prev.next
            while curr is not None:
                if curr.key == key:
                    curr.value = value
                prev = curr
                curr = curr.next
            prev.next = new_node

        return True

    def get(self, key: object) -> object:
        """Get value of key in Hash Table

        Keyword arguments:
            key: object
        Returns:
            : object or None
        """
        hash_idx = self.hash_function(key)

        if self.lst[hash_idx] is None:
            print('Not Found')
            return None
        else:
            curr = self.lst[hash_idx]
            while curr is not None:
                if curr.key == key:
                    return curr.value
                curr = curr.next

            print('Not Found')
            return None

    def delete(self, key: object) -> bool:
        """Delete node of key

        Keyword arguments:
            key: object
        Returns:
            : bool
        """
        hash_idx = self.hash_function(key)

        if self.lst[hash_idx] is None:
            print('Not Found')
            return False
        else:
            prev = None
            curr = self.lst[hash_idx]
            while curr is not None:
                if prev is None:
                    if curr.key == key:
                        self.lst[hash_idx] = self.lst[hash_idx].next
                        return True
                else:
                    if curr.key == key:
                        prev.next = curr.next
                        return True
                prev = curr
                curr = curr.next

            print('Not Found')
            return False

    def print_all(self):
        """Print Hash Table

        Returns:
            : None
        """
        print('{', end=' ')
        for node in self.lst:
            node
            while node is not None:
                print(str(node.key) + ': ' + str(node.value) + ',', end=' ')
                node = node.next
        print('}')


class HashTableTest(unittest.TestCase):
    def setUp(self):
        self.H = HashTable()

    def test_all(self):
        print('#################')
        print('# hash_function #')
        print('#################')
        key = 100
        print('self.H.hash_function(100): ', self.H.hash_function(key))
        print()

        print('print_all():', end=' ')
        self.H.print_all()
        print('#######')
        print('# put #')
        print('#######')
        print("self.H.put(123, 'Hello HashTable')")
        self.assertTrue(self.H.put(123, 'Hello HashTable'))
        print("self.H.put(123, 'test')")
        self.assertTrue(self.H.put(123, 'test'))
        print("self.H.put(1523, 'test2')")
        self.assertTrue(self.H.put(1523, 'test2'))
        print("self.H.put('fjow', 'hmm')")
        self.assertTrue(self.H.put('fjow', 'hmm'))
        print("self.H.put('a yo', 'ouya')")
        self.assertTrue(self.H.put('a yo', 'ouya'))
        print("self.H.put('zzz', 'abcd')")
        self.assertTrue(self.H.put('zzz', 'abcd'))
        print(
            'self.H.lst[self.H.hash_function(123)].value: ',
            self.H.lst[self.H.hash_function(123)].value
        )
        print('print_all():', end=' ')
        self.H.print_all()
        print()

        print('#######')
        print('# get #')
        print('#######')
        print(
            "self.H.get('aaaaaaaaaaaaaaa'): ",
            self.H.get('aaaaaaaaaaaaaaa')
        )
        self.assertIsNone(self.H.get('aaaaaaaaaaaaaaa'))
        print('self.H.get(123): ', self.H.get(123))
        self.assertEqual(self.H.get(123), 'test')
        print('self.H.get(1523): ', self.H.get(1523))
        self.assertEqual(self.H.get(1523), 'test2')
        print("self.H.get('fjow'): ", self.H.get('fjow'))
        self.assertEqual(self.H.get('fjow'), 'hmm')
        print("self.H.get('a yo'): ", self.H.get('a yo'))
        self.assertEqual(self.H.get('a yo'), 'ouya')
        print("self.H.get('zzz'): ", self.H.get('zzz'))
        self.assertEqual(self.H.get('zzz'), 'abcd')
        print()

        print('##########')
        print('# delete #')
        print('##########')
        print("self.H.delete('fjow')")
        self.assertTrue(self.H.delete('fjow'))
        print("self.H.delete('a yo')")
        self.assertTrue(self.H.delete('a yo'))
        print('print_all():', end=' ')
        self.H.print_all()
        print()
