/** Linear Search
 *
 * O(n), Omega(1)
 */

#include <stdio.h>
#include <stdbool.h>

bool linearSearch(int* arr, int arr_len, int target);

int main(void)
{
    int arr[] = {1, 5, 7, 2, 12, 6, 55};
    int arr_len = sizeof(arr) / sizeof(arr[0]);

    if (linearSearch(arr, arr_len, 55))
	{
        printf("found!\n");
    }

	printf("Not found!");
}

bool linearSearch(int* arr, int arr_len, int target)
{
    for (int i = 0; i < arr_len; i++)
	{
        if (arr[i] == target)
		{
            return true;
        }
    }

    return false;
}
