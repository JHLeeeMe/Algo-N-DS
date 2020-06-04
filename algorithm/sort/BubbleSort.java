package algorithm.sort;

/**
 * BubbleSort
 * 
 * if (arr[n] > arr[n+1]) ? swap : pass
 * 위 과정을 배열의 길이만큼 반복
 * 
 * O(n^2)
 */
public class BubbleSort {
    public static void main(String[] args) {
        int[] testArr = {4, 2, 3, 7, 9, 2, 0, 1};
        bubbleSort(testArr);

        for (int i: testArr) {
            System.out.print(i + " ");          // prints 0 1 2 2 3 4 7 9
        }
        System.out.println();
    }

    public static void bubbleSort(int[] arr) {
        int i, j;
        int n = arr.length;

        for (i=n-1; i>0; i--) {
            for(j=0; j<i; j++) {
                if (arr[j] > arr[j+1])
                    swap(arr, j, j+1);
            }
        }
    }

    private static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}