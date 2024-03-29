package algorithm.sort;

/**
 * QuickSort
 * 
 * 평균 O(NlogN)
 */
public class QuickSort {

    public static void quickSort(int[] arr) {
        sort(arr, 0, arr.length-1);
    }

    private static void sort(int[] arr, int left, int right) {
        // base case
        if (left >= right) {
            return;
        }

        int pIdx = partition(arr, left, right);
        sort(arr, left, pIdx-1);
        sort(arr, pIdx+1, right);
    }

    private static int partition(int[] arr, int left, int right) {
        int mid = (left + right) >> 1;
        swap(arr, left, mid);

        int pivot = arr[left];
        int i = left, j = right;

        while (i < j) {
            while (pivot < arr[j]) {
                j--;
            }
            while (pivot >= arr[i] && i < j) {
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

    public static void main(String[] args) {
        /**
         * 첫 partition() 실행 과정
         * arr = {80, 70, 60, 30, 10, 20, 40};
         * pivot = 30 = arr[(left + right) >> 1]
         * 
         * i                  j   : i = left, j = right
         * 30 70 60 80 10 20 40   : init
         *    i            j      : while 종료 시점
         * 30 20 60 80 10 70 40   : swap
         *       i      j         : while 종료 시점
         * 30 20 10 80 60 70 40   : swap
         *       ij               : while 종료 시점
         * 30 20 10 80 60 70 40   : swap
         *  --while문 종료--
         *       
         * 10 20 30 80 60 70 40   : swap arr[left] && arr[i]
         * 
         * return i = 2
        */
        int[] test = {80, 70, 60, 30, 10, 20, 40};
        quickSort(test);

        for (int v: test) {                     // prints 20 30 40 50 60 70 80
            System.out.print(v + " ");
        }
        System.out.println();
    }
}
