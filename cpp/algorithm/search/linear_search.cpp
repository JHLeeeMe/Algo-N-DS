/** Linear Search
 *
 *   O(n), Omega(1)
 */

#include <iostream>
#include <cassert>

#define __ASSERT(expr) assert(expr)

bool linear_search(const int* arr, int arr_len, int target);

int main(void)
{
    int arr[] = {1, 5, 7, 2, 12, 6, 55};
    int arr_len = sizeof(arr) / sizeof(arr[0]);

    __ASSERT(linear_search(arr, arr_len, 55));
    __ASSERT(linear_search(arr, arr_len, 1));
}

bool linear_search(const int* arr, int arr_len, int target)
{
    for (int i = 0; i < arr_len; i++)
    {
        if (arr[i] == target)
        {
            return true;
        }
    }
    return false;
}
