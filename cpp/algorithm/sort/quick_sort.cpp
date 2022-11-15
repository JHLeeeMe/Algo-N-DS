#include <iostream>


void quick_sort(int arr[], int size);
int partition(int arr[], int left, int right);
void sort(int arr[], int left, int right);
void swap(int arr[], int a, int b);

int main()
{
    int arr[] = {8, 3, -17, 12, 4, 0, 1, -3, 2, 4};
    int arr_len = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, arr_len);

    std::cout << "{ ";
    for (const auto& e : arr)
    {
        std::cout << e << " ";
    }
    std::cout << "}";

    return 0;
}

void quick_sort(int arr[], int size)
{
    sort(arr, 0, size - 1);
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

int partition(int arr[], int left, int right)
{
    int mid = (left + right) >> 1;
    swap(arr, left, mid);

    int pivot = arr[left];
    int i = left;
    int j = right;

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

void swap(int arr[], int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
