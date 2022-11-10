#include <iostream>
#include <memory.h>

void merge_sort(int* tmp, int* arr, int left, int right);
void merge(int* tmp, int* arr, int left, int mid, int right);

int main()
{
    int arr[] = {6, 1, 23, 54, 10, 2};
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    std::cout << "arr: { ";
    for (const auto& e : arr)
    {
        std::cout << e << " ";
    }
    std::cout << "}" << std::endl;

    int tmp[arr_len];
    memset(tmp, 0x00, arr_len);

    merge_sort(tmp, arr, 0, arr_len - 1);

    std::cout << "sorted arr: { ";
    for (const auto& e : arr)
    {
        std::cout << e << " ";
    }
    std::cout << "}" << std::endl;

    return 0;
}

void merge_sort(int* tmp, int* arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = (left + right) >> 1;
    merge_sort(tmp, arr, left, mid);
    merge_sort(tmp, arr, mid + 1, right);
    merge(tmp, arr, left, mid, right);
}

void merge(int* tmp, int* arr, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        tmp[k++] = arr[i++];
    }
    while (j <= right)
    {
        tmp[k++] = arr[j++];
    }

    for (int idx = 0; idx <= right; idx++)
    {
        arr[idx] = tmp[idx];
    }
}
