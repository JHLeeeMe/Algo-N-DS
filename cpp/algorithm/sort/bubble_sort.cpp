/** Bubble Sort
 *
 *   O(n^2), Omega(n)
 */
#include <iostream>
#include <cassert>

#define __ASSERT(expr) assert(expr)

void bubble_sort(int* arr, int arr_len);
void _swap(int* arr, int i, int j);

int main()
{
    {  // _swap() Test
        std::cout << "----------- _swap() Test ------------" << std::endl;
        int a[] = {0, 1, 2, 3, 4};
        for (int i = 0; i < 5; i++)
        {
            std::cout << a[i] << " ";
        }

        std::cout << std::endl;

        _swap(a, 0, 3);
        for (int i = 0; i < 5; i++)
        {
            std::cout << a[i] << " ";
        }
    }

    std::cout << std::endl;

    {  // bubble_sort() Test
        std::cout << "----------- bubble_sort() Test ------------" << std::endl;
        int arr[] = {10, 5, 2, 765, 12, 3};
        int arr_len = sizeof(arr) / sizeof(arr[0]);

        for (int i = 0; i < arr_len; i++)
        {
            std::cout << arr[i] << " ";
        }

        std::cout << std::endl;

        bubble_sort(arr, arr_len);

        for (int i = 0; i < arr_len; i++)
        {
            std::cout << arr[i] << " ";
        }
    }

    std::cout << std::endl;

    {  // Omega(n) Test
        std::cout << "----------- Omega(n) Test ------------" << std::endl;
        int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int arr_len = sizeof(arr) / sizeof(arr[0]);

        for (int i = 0; i < arr_len; i++)
        {
            std::cout << arr[i] << " ";
        }

        std::cout << std::endl;

        bubble_sort(arr, arr_len);

        for (int i = 0; i < arr_len; i++)
        {
            std::cout << arr[i] << " ";
        }
    }

    return 0;
}

void bubble_sort(int* arr, int arr_len)
{
    int n = 1;
    while (n != arr_len)
    {
        std::cout << "n: " << n << std::endl;
        bool condition = true;
        for (int i = 0; i < arr_len - n; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                _swap(arr, i, i + 1);
                condition = false;
            }
        }

        // for Omega(n)
        if (condition)
        {
            std::cout << std::endl;
            std::cout << "FOR THE OMEGA!" << std::endl;
            break;
        }

        n++;
    }
}

void _swap(int* arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
