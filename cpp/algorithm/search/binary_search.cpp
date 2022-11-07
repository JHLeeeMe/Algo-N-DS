/** Binary Search
 *
 *   O(logN), Omega(1)
 */
#include <cassert>

#define __ASSERT(expr) assert(expr)

bool binary_search(int* arr, int first, int last, int target);

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 61, 72, 83, 94};

    int arr_len = sizeof(arr) / sizeof(arr[0]);
    __ASSERT(binary_search(arr, 0, arr_len - 1, 4));
    __ASSERT(binary_search(arr, 0, arr_len - 1, 0));
    __ASSERT(binary_search(arr, 0, arr_len - 1, -1) == false);
    __ASSERT(binary_search(arr, 0, arr_len - 1, -121) == false);
    __ASSERT(binary_search(arr, 0, arr_len - 1, 83) == false);

    return 0;
}

bool binary_search(int* arr, int first, int last, int target)
{
    if (first > last)
    {
        return false;
    }

    int mid = (first + last) >> 1;
    if (mid == target)
    {
        return true;
    }
    else if (mid < target)
    {
        return binary_search(arr, mid + 1, last, target);
    }
    else
    {
        return binary_search(arr, 0, mid - 1, target);
    }
}

