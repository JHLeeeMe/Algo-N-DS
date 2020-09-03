/** Insertion Sort
 *
 * O(n^2), Omega(n^2)
 *
 * void insertion_sort(int arr[], int arr_len);
 */

#include <stdio.h>

void insertion_sort(int arr[], int arr_len);

int main(void)
{
    printf("##################\n");
    printf("# arr[], arr_len #\n");
    printf("##################\n");
    int arr[] = { 5, 2, 10, 3, 1, 0, 9 };
    int arr_len = sizeof(arr) / sizeof(int);
    printf("arr: { ");
    for (int i = 0; i < arr_len; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
    printf("arr_len: %d\n", arr_len);
    printf("\n");

    printf("################################\n");
    printf("# insertion_sort(arr, arr_len) #\n");
    printf("################################\n");
    insertion_sort(arr, arr_len);

    printf("sorted arr: { ");
    for (int i = 0; i < arr_len; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}

/*
 * Function: insertion_sort
 * ------------------------
 * Insertion Sort array
 *
 *  params: int arr[], int arr_len
 *  returns: void
 */
void insertion_sort(int arr[], int arr_len)
{
    for (int i = 1; i < arr_len; i++) {
        int tmp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}
