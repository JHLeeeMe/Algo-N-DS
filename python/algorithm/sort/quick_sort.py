import unittest


def quick_sort(lst: list) -> None:
    _sort(lst, 0, len(lst) - 1)


def _sort(lst: list, left: int, right: int) -> None:
    if left >= right:
        return

    pivot_idx = partition(lst, left, right)
    _sort(lst, left, pivot_idx - 1)
    _sort(lst, pivot_idx + 1, right)


def partition(lst: list, left: int, right: int) -> int:
    mid = (left + right) >> 1
    swap(lst, left, mid)

    pivot = lst[left]
    i = left
    j = right

    while i < j:
        while pivot < lst[j]:
            j -= 1
        while pivot >= lst[i] and i < j:
            i += 1
        swap(lst, i, j)

    lst[left] = lst[i]
    lst[i] = pivot
    return i


def swap(lst: list, a: int, b: int) -> None:
    tmp = lst[a]
    lst[a] = lst[b]
    lst[b] = tmp


class QuickSortTest(unittest.TestCase):
    def setUp(self):
        self.lst = [10, 2, 5, 123, 3, 82]

    def test_empty_list(self):
        empty_list = []
        quick_sort(empty_list)
        self.assertListEqual(empty_list, [])

    def test_quick_sort(self):
        quick_sort(self.lst)
        self.assertListEqual(self.lst, [2, 3, 5, 10, 82, 123])
