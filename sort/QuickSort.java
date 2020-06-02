package sort;

/**
 * QuickSort
 */
public class QuickSort {
    public static void main(String[] args) {
        int[] test = {80, 70, 60, 50, 30, 20, 40};
        quickSort(test, 0, test.length-1);

        for (int v: test) {
            System.out.println(v);
        }
    }

    public static void quickSort(int[] arr, int left, int right) {
        if (left >= right) return;

        int pIdx = partition(arr, left, right);
        quickSort(arr, left, pIdx-1);
        quickSort(arr, pIdx+1, right);
    }

    private static int partition(int[] arr, int left, int right) {
        int mid = (left + right) / 2;
        swap(arr, left, mid);

        int pivot = arr[left];
        int i = left, j = right;

        while(i < j) {
            while(pivot < arr[j]) {
                j--;
            }

            while(pivot >= arr[i] && i < j) {
                i++;
            }
            swap(arr, i, j);
        }
        arr[left] = arr[i];
        arr[i] = pivot;

        return i;
    }

    private static void swap(int[] arr, int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b]= tmp;
    }
}
