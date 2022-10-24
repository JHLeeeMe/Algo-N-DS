/** Quick Sort
 *
 * O(NlogN), Omega(NlogN)
 * worst: O(n^2)
 *  e.g. sorted array
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void quick_sort(int32_t arr[], uint32_t size);
uint32_t partition(int32_t arr[], int32_t left, int32_t right);
void sort(int32_t arr[], int32_t left, int32_t right);
void swap(int32_t arr[], int32_t i, int32_t j);

int32_t main(void)
{
    int32_t arr[] = { 5, 1, 2, 10, 8, 0, 23, 7 };
    uint32_t size = sizeof(arr) / sizeof(int32_t);

    quick_sort(arr, size);

    printf("{ ");
    for (uint32_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}

/*
 * Function: quick_sort
 * -------------------
 * Execute sort function
 *
 *  params: int32_t arr[], uint32_t size
 *  returns: void
 */
void quick_sort(int32_t arr[], uint32_t size)
{
    sort(arr, 0, size);
}

/*
 * Function: sort
 * -------------------
 * Sort arr[] between left to right
 *
 *  params: int32_t arr[], int32_t left, int32_t right
 *  returns: void
 */
void sort(int32_t arr[], int32_t left, int32_t right)
{
    // base case
    if (left >= right)
    {
        return;
    }

    uint32_t pivot_idx = partition(arr, left, right);
    sort(arr, left, pivot_idx - 1);
    sort(arr, pivot_idx + 1, right);
}

/*
 * Function: partition
 * -------------------
 * Return pivot index
 *
 *  params: int32_t arr[], int32_t left, int32_t right
 *  returns: uint32_t
 */
uint32_t partition(int32_t arr[], int32_t left, int32_t right)
{
    int32_t mid = (left + right) >> 1;
    swap(arr, left, mid);

    int32_t pivot = arr[left];
    int32_t i = left, j = right;

    while (i < j)
    {
        while (pivot < arr[j])
        {
            j--;
        }
        while (pivot >= arr[i] && i < j)
        {
            i++;
        }
        swap(arr, i, j);
    }
    arr[left] = arr[i];
    arr[i] = pivot;

    return i;
}

/*
 * Function: swap
 * -------------------
 * Swap arr[] elements
 *
 *  params: int32_t arr[], int32_t a, int32_t b
 *  returns: void
 */
void swap(int32_t arr[], int32_t a, int32_t b)
{
    int32_t tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
