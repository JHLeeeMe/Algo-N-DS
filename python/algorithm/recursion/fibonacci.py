"""Fibonacci

0, 1, 1, 2, 3, 5, 8, ...
"""
import unittest


def fibonacci(x: int) -> int:
    if x <= 1:
        return x

    return fibonacci(x - 2) + fibonacci(x - 1)


def fibonacci_tailrec(x: int, a: int = 0, b: int = 1) -> int:
    if x == 0:
        return a
    if x == 1:
        return b

    return fibonacci_tailrec(x - 1, b, a + b)


class FibonacciTest(unittest.TestCase):
    def setUp(self):
        self.lst = []

    def test_fibonacci(self):
        for i in range(7):
            self.lst.append(fibonacci(i))
        self.assertListEqual(self.lst, [0, 1, 1, 2, 3, 5, 8])

    def test_fibonacci_tailrec(self):
        for i in range(7):
            self.lst.append(fibonacci_tailrec(i))
        self.assertListEqual(self.lst, [0, 1, 1, 2, 3, 5, 8])
