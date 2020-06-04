package algorithm.sort;

/**
 * MergeSort
 * 
 * If not left >= right
 * 1. Find the middle point to divide the array into two halves:  
 *         middle m = (l+r)/2
 * 2. Call mergeSort for first half:   
 *         Call sort(arr, l, m)
 * 3. Call mergeSort for second half:
 *         Call sort(arr, m+1, r)
 * 4. Merge the two halves sorted in step 2 and 3:
 *         Call merge(arr, l, m, r)
 *
 * O(NlogN)
 */
public class MergeSort {
    public static void main(String[] args) {
        int[] test = {84, 12, 442, 11, 1, 23};
        mergeSort(test);

        for (int e : test)                  // prints 1 11 12 23 84 442
            System.out.print(e + " ");

        System.out.println();
    }

    public static void mergeSort(int[] arr) {
        sort(arr, 0, arr.length-1);
    }

    private static void sort(int[] arr, int left, int right) {
        // base case
        if (left >= right)              // left == right는 쪼개다가 엘리먼트가 하나인 상황
            return;

        // 엘러먼트가 두개 이상이면 분할 및 합병
        int mid = (left + right) / 2;
        sort(arr, left, mid);
        sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }

    private static void merge(int[] arr, int left, int mid, int right) {
        int i = left;               // 왼쪽 배열의 시작위치
        int j = mid + 1;            // 오른쪽 배열의 시작위치

        int[] tmp = new int[arr.length];
        int k = left;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                tmp[k++] = arr[i++];
            } else {
                tmp[k++] = arr[j++];
            }
        }
        while (i <= mid) {
            tmp[k++] = arr[i++];
        }
        while (j <= right) {
            tmp[k++] = arr[j++];
        }

        for (int idx=left; idx<=right; idx++) {
            arr[idx] = tmp[idx];
        }
    }
}