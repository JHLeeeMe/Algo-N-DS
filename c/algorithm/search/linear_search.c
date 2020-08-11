/** Linear Search
 *
 * O(n), Omega(1)
 */

#include <stdio.h>
#include <stdbool.h>

bool linearSearch(int *arr, int arr_len, int i);

int main(void)
{
    int arr[] = {1, 5, 7, 2, 12, 6, 55};
    int arr_len = sizeof(arr) / sizeof(arr[0]);

    if (linearSearch(arr, arr_len, 55))
        printf("found!\n");
    else
        printf("Not found!");

    return 0;
}

bool linearSearch(int *arr, int arr_len, int i)
{
    for (int j = 0; j < arr_len; j ++)
    {
        if (arr[j] == i)
            return true;
    }
    return false;
}
