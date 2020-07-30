import unittest


def merge_sort(lst: list) -> None:
    __sort(lst, 0, len(lst) - 1)


def __sort(lst: list, left: int, right: int) -> None:
    # base case
    if left >= right:
        return

    mid = (left + right) >> 1
    __sort(lst, left, mid)
    __sort(lst, mid + 1, right)
    merge(lst, left, mid, right)


def merge(lst: list, left: int, mid: int, right: int) -> None:
    i = left
    j = mid + 1

    tmp = [None] * len(lst)
    k = left

    while i <= mid and j <= right:
        if lst[i] <= lst[j]:
            tmp.insert(k, lst[i])
            # tmp[k] = lst[i]
            i += 1
        else:
            tmp.insert(k, lst[j])
            # tmp[k] = lst[j]
            j += 1
        k += 1

    while i <= mid:
        tmp.insert(k, lst[i])
        # tmp[k] = lst[i]
        k += 1
        i += 1

    while j <= right:
        tmp.insert(k, lst[j])
        # tmp[k] = lst[j]
        k += 1
        j += 1

    for idx in range(left, right + 1):
        lst[idx] = tmp[idx]


class MergeSortTest(unittest.TestCase):
    def setUp(self):
        self.lst = [4, 129, 23, 1010, 10, 1, 48, 22]

    def test_empty_list(self):
        empty_list = []

        merge_sort(empty_list)
        self.assertListEqual(empty_list, [])

    def test_merge_sort(self):
        with self.assertRaises(NameError):
            __sort(self.lst, 0, len(self.lst) - 1)

        merge_sort(self.lst)
        self.assertListEqual(self.lst, [1, 4, 10, 22, 23, 48, 129, 1010])
