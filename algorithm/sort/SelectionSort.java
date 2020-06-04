package algorithm.sort;

/**
 * SelectionSort
 * 
 * 1. 순차적으로 돌며 가장 작은 값을 minIdx로 할당
 * 2. 1번에서 minIdx가 바뀌었다면 swap
 * 위 과정을 (배열의 길이 - 1)번 반복
 * 
 * O(n^2)
 */
public class SelectionSort {
    public static void main(String[] args) {
        int[] testArray = {1, 1234, 5, 1112, 5, 3, 52};
        selectionSort(testArray);

        for (int i : testArray) {                   // prints 1 3 5 5 52 1112 1234
            System.out.print(i + " ");
        }
    }

    public static void selectionSort(int[] arr) {
        int n = arr.length;
        int minIdx;

        for (int i=0; i<n-1; i++) {
            minIdx = i;

            for (int j=i+1; j<n; j++) {
                if (arr[j] < arr[minIdx]) 
                    minIdx = j;
            }

            // swap if (minIdx != i)
            if (i != minIdx) 
                swap(arr, i, minIdx);
        }
    }

    private static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}