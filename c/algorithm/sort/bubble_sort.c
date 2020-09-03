/** Bubble Sort
 * 
 * O(n^2), Omega(n)
 */

#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int nArr[], int nArr_len);
void swap(int nArr[], int i, int j);

int main(void)
{
    int nArr[] = {5, 7, 1, 3, 2, 10, 9, 45};
    int nArr_len = sizeof(nArr) / sizeof(nArr[0]);

    bubbleSort(nArr, nArr_len);

    for (int i = 0; i < nArr_len; i++) {
        printf("%d ", nArr[i]);
    }

    return 0;
}

void bubbleSort(int nArr[], int nArr_len)
{
    for (int i = nArr_len - 1; i > 0; i--) {

        bool condition = true;
        for (int j = 0; j < i; j++) {

            if (nArr[j] > nArr[j + 1]) {
                swap(nArr, j, j + 1);
                condition = false;
            }
        }

        // for Omega(n)
        if (condition) break;
    }
}

void swap(int nArr[], int i, int j)
{
    int tmp = nArr[i];
    nArr[i] = nArr[j];
    nArr[j] = tmp;
}
