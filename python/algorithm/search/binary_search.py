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

    def __rec_search(self, arr, item: int,
                     low: int, high: int) -> int:
        if (low > high):
            return -1

        mid = (low + high) >> 1
        if item == arr[mid]:
            return mid
        elif item < arr[mid]:
            self.rec_search(arr, item, low, mid - 1)
        else:
            self.rec_search(arr, item, mid + 1, high)


class BinarySearchTest(unittest.TestCase):
    def test_search(self):
        pass

    def test_rec_search(self):
        pass
