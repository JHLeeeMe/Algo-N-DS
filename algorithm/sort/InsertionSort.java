package algorithm.sort;

/**
 * InsertionSort
 * 
 * 1. 삽입할 값을 tmp로 할당. => int tmp = arr[i]
 * 2. 삽입할 값의 이전 인덱스 값과 비교
 * 3. 이전 인덱스 값을 다음 인덱스로 복사 if (삽입할 값이 더 작으면)
 * 4. 2, 3을 반복하다가 복사가 이루어지지 않았아면 tmp 삽입
 * 위 과정을 (배열 길이 - 1) 만큼 반복
 * 
 * O(n^2)
 */
public class InsertionSort {
    public static void main(String[] args) {
        int[] arr = {10, 5, 22, 1, 3, 123};
        insertionSort(arr);

        for (int i: arr) {                          // prints 1 3 5 10 22 123
            System.out.print(i + " ");
        }
        System.out.println();
    }

    private static void insertionSort(int[] arr) {
        int i;
        int n = arr.length;

        for (i=1; i<n; i++) {
            int tmp = arr[i];
            int j = i-1;

            while(j >= 0 && tmp < arr[j]) {
                arr[j + 1] = arr[j];        // 오른쪽으로 복사

                j--;                        // 비교할 인덱스 왼쪽으로 이동
            }
            arr[j + 1] = tmp;
        }
    }
}