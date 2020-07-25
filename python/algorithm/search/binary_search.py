import unittest


class BinarySearch:
    def search(self, arr, item: int) -> int:
        low = 0
        high = len(arr) - 1
        mid = None

        while low <= high:
            mid = (low + high) >> 1
            if item == arr[mid]:
                return mid
            elif item < arr[mid]:
                high = mid - 1
            else:
                low = mid + 1

        return -1

    def rec_search(self, arr, item: int,
                   low: int, high: int) -> int:
        if (low > high):
            return -1

        mid = (low + high) >> 1
        if item == arr[mid]:
            return mid
        elif item < arr[mid]:
            return self.rec_search(arr, item, low, mid - 1)
        else:
            return self.rec_search(arr, item, mid + 1, high)


class BinarySearchTest(unittest.TestCase):
    def setUp(self):
        self.lst = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        self.low = 0
        self.high = len(self.lst) - 1

    def test_search(self):
        bs = BinarySearch()

        idx = bs.search(self.lst, 11)
        self.assertEqual(idx, -1)

        idx = bs.search(self.lst, 5)
        self.assertEqual(idx, 4)

    def test_rec_search(self):
        bs = BinarySearch()

        idx = bs.rec_search(self.lst, 123123, self.low, self.high)
        self.assertEqual(idx, -1)

        idx = bs.rec_search(self.lst, 5, self.low, self.high)
        self.assertEqual(idx, 4)
