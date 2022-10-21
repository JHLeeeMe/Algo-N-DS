package algorithm.sort;

/**
 * HeapSort
 * 
 * heap 자료구조를 활용한 sort
 * max_heap의 경우:
 *      1. 0번째 인덱스와 마지막 인덱스 swap
 *      2. heap size - 1, and heapify 
 *      3. 1, 2 반복
 * 
 * heapify 하는데 O(logN), 
 * heapify 작업을 N-1번 실행 
 * O(NlogN)
 */
public class HeapSort {
    public static void main(String[] args) {
        int[] arr = {12, 11, 13, 5, 6, 7};

        HeapSort ob = new HeapSort();
        ob.sort(arr);

        printArray(arr);
    }

    void sort(int[] arr) {
        int n = arr.length;

        // create max_heap
        for (int i=n/2-1; i>=0; i--)
            heapify(arr, n, i);

        // max_heap to asc_sorted_array
        for (int i=n-1; i>0; i--) {
            int tmp = arr[0];
            arr[0] = arr[i];
            arr[i] = tmp;

            heapify(arr, i, 0);
        }
    }

    void heapify(int[] arr, int n, int idx) {
        int root = idx;
        int left = 2*idx + 1;
        int right = 2*idx + 2;

        if (left < n && arr[left] > arr[root])
            root = left;

        if (right < n && arr[right] > arr[root])
            root = right;

        if (root != idx) {
            int tmp = arr[idx];
            arr[idx] = arr[root];
            arr[root] = tmp;

            heapify(arr, n, root);
        }
    }

    static void printArray(int[] arr) {
        for (int i: arr)
            System.out.print(i + " ");
            System.out.println();
    }
}