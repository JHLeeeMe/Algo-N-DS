import unittest


def heap_sort(lst: list):
    n = len(lst)

    # create max heap
    for i in reversed(range(n/2)):
        heapify(lst, n, i)

    # to asc_sorted_list
    for i in range(n - 1, 0, -1):
        tmp = lst[0]
        lst[0] = lst[i]
        lst[i] = tmp

        heapify(lst, i, 0)


def heapify(lst: list, heap_size: int, root_idx: int):
    pass


class HeapSortTest(unittest.TestCase):
    def setUp(self):
        pass

    def test_empty_list(self):
        pass

    def test_all(self):
        pass
