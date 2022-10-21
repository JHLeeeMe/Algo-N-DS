/** Binary Search
 *
 * O(logN), Omega(1)
 */

#include <stdio.h>
#include <stdbool.h>

bool binarySearch(int nArr[], int nFirst, int nLast, int nTarget);

int main(void)
{
    int nArr[] = {1, 3, 5, 6, 10, 11, 14, 15, 50};
    int nArr_len = sizeof(nArr) / sizeof(nArr[0]);

    bool condition = binarySearch(nArr, 0, nArr_len - 1, 50);
    if (condition)
	{
        printf("found!");
    }
	else
	{
        printf("Not found!");
    }

    return 0;
}

bool binarySearch(int nArr[], int nFirst, int nLast, int nTarget)
{
    if (nFirst > nLast)
	{
        return false;
    }

    int nMid = (nLast + nFirst) >> 1;

    if (nArr[nMid] == nTarget)
	{
        return true;
    }
	else if (nArr[nMid] < nTarget)
	{
        return binarySearch(nArr, nMid + 1, nLast, nTarget);
    }
	else
	{
        return binarySearch(nArr, nFirst, nMid - 1, nTarget);
    }
}
