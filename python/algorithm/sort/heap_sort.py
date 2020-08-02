import unittest


def heap_sort(lst: list) -> None:
    n = len(lst)

    # create max_heap
    # for i in reversed(range(n >> 1)):
    #     heapify(lst, n, i)
    for i in range((n >> 1)-1, -1, -1):
        heapify(lst, heap_size=n, idx=i)

    # to asc_sorted_list
    for i in range(n - 1, 0, -1):
        tmp = lst[0]
        lst[0] = lst[i]
        lst[i] = tmp

        heapify(lst, heap_size=i, idx=0)


def heapify(lst: list, heap_size: int, idx: int) -> None:
    root = idx
    left = 2*idx + 1
    right = 2*idx + 2

    if left < heap_size and lst[left] > lst[root]:
        root = left

    if right < heap_size and lst[right] > lst[root]:
        root = right

    if root != idx:
        tmp = lst[idx]
        lst[idx] = lst[root]
        lst[root] = tmp

        heapify(lst, heap_size, root)


class HeapSortTest(unittest.TestCase):
    def setUp(self):
        self.lst = [4, 10, 2, 1, 60, 23]

    def test_empty_list(self):
        empty_list = []
        self.assertListEqual(empty_list, [])

    def test_all(self):
        heap_sort(self.lst)
        self.assertListEqual(self.lst, [1, 2, 4, 10, 23, 60])
