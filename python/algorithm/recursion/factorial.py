"""Factorial

0! = 1
1! = 1 * 0!
2! = 2 * 1!
3! = 3 * 2!
...
"""
import unittest


def factorial(x: int) -> int:
    if x == 0:
        return 1

    return x * factorial(x - 1)


def factorial_tailrec(x: int, result: int = 1) -> int:
    if x < 0:
        return result

    return factorial_tailrec(x - 1, x * result)


class FactorialTest(unittest.TestCase):
    def factorial_test(self):
        self.assertEqual(factorial(0), 1)
        self.assertEqual(factorial(1), 1)
        self.assertEqual(factorial(2), 2)
        self.assertEqual(factorial(3), 6)
        self.assertEqual(factorial(4), 24)

    def factorial_tailrec_test(self):
        self.assertEqual(factorial_tailrec(0), 1)
        self.assertEqual(factorial_tailrec(1), 1)
        self.assertEqual(factorial_tailrec(2), 2)
        self.assertEqual(factorial_tailrec(3), 6)
        self.assertEqual(factorial_tailrec(4), 24)
