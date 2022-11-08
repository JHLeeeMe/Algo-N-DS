/** Insertion Sort
 *
 *   O(n^2), Omega(n^2)
 */
#include <iostream>

void insertion_sort(int* arr, int arr_len);

int main()
{
    {
        int arr[] = {10, 2, 13, 53, 0, -342, 3, 99, 101, 1000};
        int arr_len = sizeof(arr) / sizeof(arr[0]);

        insertion_sort(arr, arr_len);

        for (int i = 0; i < arr_len; i++)
        {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
    {
        int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int arr_len = sizeof(arr) / sizeof(arr[0]);

        insertion_sort(arr, arr_len);

        for (int i = 0; i < arr_len; i++)
        {
            std::cout << arr[i] << " ";
        }
    }

    return 0;
}

void insertion_sort(int* arr, int arr_len)
{
    for (int i = 1; i < arr_len; i++)
    {
        int tmp = arr[i];
        int cursor = i - 1;

        while (cursor >= 0 && arr[cursor] > tmp)
        {
            arr[cursor + 1] = arr[cursor];
            cursor--;
        }
        arr[cursor + 1] = tmp;
    }
}
