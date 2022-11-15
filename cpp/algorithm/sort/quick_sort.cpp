#include <iostream>


void quick_sort(int arr[], int size);
int partition(int arr[], int left, int right);
void sort(int arr[], int left, int right);
void swap(int arr[], int a, int b);

int main()
{
    return 0;
}

void quick_sort(int arr[], int size)
{
    sort(arr, 0, size);
}

int partition(int arr[], int left, int right)
{
    return 0;
}

void sort(int arr[], int left, int right)
{
    // base case
    if (left >= right)
    {
        return;
    }

    int pivot_idx = partition(arr, left, right);
    sort(arr, left, pivot_idx - 1);
    sort(arr, pivot_idx + 1, right);
}

void swap(int arr[], int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
