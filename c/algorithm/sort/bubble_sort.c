/** Bubble Sort
 * 
 * O(n^2), Omega(n^2)
 */

#include <stdio.h>

void bubbleSort(int arr[], int size);

int main(void)
{
    int arr[] = {5, 7, 1, 3, 2, 10, 9, 45};
    int arr_length = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, arr_length);

    for (int i = 0; i < arr_length; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void bubbleSort(int arr[], int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
