/** Selection Sort
 *
 * O(n^2), Omega(n^2)
 */

#include <stdio.h>

void selectionSort(int arr[], int arr_len);
void swap(int arr[], int i, int j);

int main(void)
{
    int arr[] = {50, 1, 35, 33, 12, 222};
    int arr_len = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, arr_len);

    for (int i = 0; i < arr_len; i++)
    {
        printf("%d ", arr[i]);
    }
}

void selectionSort(int arr[], int arr_len)
{
    int i, j;
    int min_idx;

    for (i = 0; i < arr_len - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < arr_len; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr, i, min_idx);
    }
}

void swap(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
