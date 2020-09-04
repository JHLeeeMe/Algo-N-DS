/** Quick Sort
 *
 * O(NlogN), Omega()
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
}

void quick_sort(int32_t arr[], uint32_t size)
{
    sort(arr, 0, size);
}

void sort(int32_t arr[], int32_t left, int32_t right)
{
    // base case
    if (left >= right) {
        return;
    }

    uint32_t p_idx = partition(arr, left, right);
    sort(arr, left, p_idx - 1);
    sort(arr, p_idx + 1, right);
}

uint32_t partition(int32_t* arr, int32_t left, int32_t right)
{
    int32_t mid = (left + right) >> 1;
    swap(arr, left, mid);

    int32_t pivot = arr[left];
    int32_t i = left, j = right;

    while (i < j) {
        while (pivot < arr[j]) {
            j--;
        }
        while (pivot >= arr[i] && i < j) {
            i++;
        }
        swap(arr, i, j);
    }
    arr[left] = arr[i];
    arr[i] = pivot;

    return i;
}

void swap(int32_t arr[], int32_t a, int32_t b)
{
    int32_t tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
