import unittest


def selection_sort(lst: list) -> None:
    n = len(lst)

    for i in range(n - 1):
        min_idx = i
        j = i + 1

        while j < n:
            if lst[j] < lst[min_idx]:
                min_idx = j
            j += 1

        # for j in range(i + 1, n):
        #     if lst[j] < lst[min_idx]:
        #         min_idx = j

        if (i != min_idx):
            swap(lst, i, min_idx)


def swap(lst: list, a: int, b: int) -> None:
    tmp = lst[a]
    lst[a] = lst[b]
    lst[b] = tmp


class SelectionSortTest(unittest.TestCase):
    def setUp(self):
        self.lst = [1000, 1, 4, 500, 2, 5, 23]

    def test_empty_list(self):
        empty_list = []
        selection_sort(empty_list)
        self.assertListEqual(empty_list, [])

    def test_swap(self):
        swap(self.lst, 0, -1)
        self.assertEqual(self.lst[0], 23)
        self.assertEqual(self.lst[-1], 1000)
        # print(self.lst)

    def test_selection_sort(self):
        selection_sort(self.lst)
        self.assertListEqual(self.lst, [1, 2, 4, 5, 23, 500, 1000])
