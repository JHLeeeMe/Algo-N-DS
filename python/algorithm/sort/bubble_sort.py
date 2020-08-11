import unittest


def bubble_sort(lst: list) -> None:
    n = len(lst)

    for i in range(n - 1, 0, -1):
        condition = True
        for j in range(i):
            if lst[j] > lst[j + 1]:
                swap(lst, j, j + 1)
                condition = False

        # for Omega(n)
        if condition:
            break


def swap(lst: list, a: int, b: int) -> None:
    tmp = lst[a]
    lst[a] = lst[b]
    lst[b] = tmp


class BubbleSortTest(unittest.TestCase):
    def setUp(self):
        self.lst = [30, 7, 12, 44, 1, 3, 5, 4, 29, 2]

    def test_swap(self):
        swap(self.lst, 0, 1)
        self.assertEqual(self.lst[0], 7)
        self.assertEqual(self.lst[1], 30)
        # print(self.lst)

    def test_empty_list(self):
        empty_list = []
        bubble_sort(empty_list)
        self.assertListEqual(empty_list, [])

    def test_bubble_sort(self):
        bubble_sort(self.lst)
        self.assertListEqual(
            self.lst, [1, 2, 3, 4, 5, 7, 12, 29, 30, 44]
        )
