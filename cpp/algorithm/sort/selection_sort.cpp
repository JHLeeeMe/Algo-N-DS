/** Selection Sort
 *
 *   O(n^2), Omega(n^2)
 */
#include <iostream>

void selection_sort(int* arr, int arr_len);
void _swap(int* arr, int i, int j);

int main()
{
    {
        int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        int arr_len = sizeof(arr) / sizeof(arr[0]);

        selection_sort(arr, arr_len);
        for (int i = 0; i < arr_len; i++)
        {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
    {
        int arr[] = {9, 6, -3, 0, 61, 99, 7};
        int arr_len = sizeof(arr) / sizeof(arr[0]);

        selection_sort(arr, arr_len);
        for (int i = 0; i < arr_len; i++)
        {
            std::cout << arr[i] << " ";
        }
    }

    return 0;
}

void selection_sort(int* arr, int arr_len)
{
    for (int i = 0; i < arr_len - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < arr_len; j++)
        {
            if (arr[min_idx] > arr[j])
            {
                min_idx = j;
            }
        }

        if (i != min_idx)
        {
            _swap(arr, i, min_idx);
        }
    }
}

void _swap(int* arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
