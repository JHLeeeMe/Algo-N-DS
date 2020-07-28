import unittest


def insertion_sort(lst: list) -> None:
    for i in range(1, len(lst)):
        tmp = lst[i]
        j = i - 1

        while j >= 0 and tmp < lst[j]:
            lst[j + 1] = lst[j]
            j -= 1

        lst[j + 1] = tmp


class InsertionSortTest(unittest.TestCase):
    def setUp(self):
        self.lst = [4, 2, 1, 30, 24, 32, 5, 7]

    def insertion_sort_test(self):
        insertion_sort(self.lst)
        self.assertListEqual(self.lst, [1, 2, 4, 5, 7, 24, 30, 32])
