package sort;

/**
 * SelectionSort
 */
public class SelectionSort {
    public static void main(String[] args) {
        int[] testArray = {1, 1234, 5, 1112, 5, 3, 52};
        selectionSort(testArray);

        for (int i : testArray) {
            System.out.printf(i + " ");
        }
    }

    public static void selectionSort(int[] array) {
        int n = array.length;
        int minIdx;

        for (int i=0; i<n-1; i++) {
            minIdx = i;

            for (int j=i+1; j<n; j++) {
                if (array[j] < array[minIdx]) 
                    minIdx = j;
            }

            // swap
            int tmp = array[i];
            array[i] = array[minIdx];
            array[minIdx] = tmp;
        }
    }
}