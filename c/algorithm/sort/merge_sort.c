///** Merge Sort
// *
// * O(NlogN), Omega(NlogN)
// */
//#include <stdio.h>
//
//int nArr[] = {1, 5, 2, 10, 32, 12, 60, 87, 7};
//int nArr_len = sizeof(nArr) / sizeof(nArr[0]);
//int nTmp[sizeof(nArr) / sizeof(nArr[0])];
//
//void mergeSort(int nArr[], int nLeft, int nRight);
//void merge(int nArr[], int nLeft, int nMid, int nRight);
//
//int main(void)
//{
//    for (int i = 0; i < nArr_len; i++)
//        printf("%d ", nArr[i]);
//    printf("\n");
//
//    mergeSort(nArr, 0, nArr_len - 1);
//
//    for (int i = 0; i < nArr_len; i++)
//        printf("%d ", nArr[i]);
//}
//
//void mergeSort(int nArr[], int nLeft, int nRight)
//{
//    // base case
//    if (nLeft >= nRight)
//        return;
//
//    int nMid = (nLeft + nRight) >> 1;
//    mergeSort(nArr, nLeft, nMid);
//    mergeSort(nArr, nMid + 1, nRight);
//    merge(nArr, nLeft, nMid, nRight);
//}
//
//void merge(int nArr[], int nLeft, int nMid, int nRight)
//{
//    int i = nLeft;
//    int j = nMid + 1;
//    int k = nLeft;
//
//    while (i <= nMid && j <= nRight)
//    {
//        if (nArr[i] <= nArr[j])
//            nTmp[k++] = nArr[i++];
//        else
//            nTmp[k++] = nArr[j++];
//    }
//
//    while (i <= nMid)
//        nTmp[k++] = nArr[i++];
//
//    while (j <= nRight)
//        nTmp[k++] = nArr[j++];
//
//    for (int idx = nLeft; idx <= nRight; idx++)
//        nArr[idx] = nTmp[idx];
//}

/** Merge Sort
 *
 * O(NlogN), Omega(NlogN)
 */
#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *nArr, int *nTmp, int nLeft, int nRight);
void merge(int *nArr, int *nTmp, int nLeft, int nMid, int nRight);

int main(void)
{
    int nArr[] = {1, 99, 5, 2, 10, 32, 12, 60, 87, 7};
    int nArr_len = sizeof(nArr) / sizeof(nArr[0]);
    int *nTmp = malloc(sizeof(nArr));

    for (int i = 0; i < nArr_len; i++)
        printf("%d ", nArr[i]);
    printf("\n");

    mergeSort(nArr, nTmp, 0, nArr_len - 1);

    for (int i = 0; i < nArr_len; i++)
        printf("%d ", nArr[i]);

    free(nTmp);
}

void mergeSort(int *nArr, int *nTmp, int nLeft, int nRight)
{
    // base case
    if (nLeft >= nRight)
        return;

    int nMid = (nLeft + nRight) >> 1;
    mergeSort(nArr, nTmp, nLeft, nMid);
    mergeSort(nArr, nTmp, nMid + 1, nRight);
    merge(nArr, nTmp, nLeft, nMid, nRight);
}

void merge(int *nArr, int *nTmp, int nLeft, int nMid, int nRight)
{
    int i = nLeft;
    int j = nMid + 1;
    int k = nLeft;

    while (i <= nMid && j <= nRight)
    {
        if (nArr[i] <= nArr[j])
            nTmp[k++] = nArr[i++];
        else
            nTmp[k++] = nArr[j++];
    }

    while (i <= nMid)
        nTmp[k++] = nArr[i++];

    while (j <= nRight)
        nTmp[k++] = nArr[j++];

    for (int idx = nLeft; idx <= nRight; idx++)
        nArr[idx] = nTmp[idx];
}
