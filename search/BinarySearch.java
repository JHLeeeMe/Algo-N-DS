package search;

public class BinarySearch {

    public static void main(String[] args) {
        int[] sortedArr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        int idx1 = binarySearch(sortedArr, 9);
        int idx2 = recBinarySearch(sortedArr, 0, 0, sortedArr.length);

        System.out.println(idx1);
        System.out.println();
        System.out.println(idx2);
    }

    public static int binarySearch(int[] arr, int x) {
        int low = 0;
        int high = arr.length - 1;
        int mid;

        while(low <= high) {

            mid = (low + high) / 2;
            if (x == arr[mid]) 
                return mid;
            else if (x < arr[mid]) 
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return -1;
    }

    // 재귀적 이분탐색
    private static int recBinarySearch(int[] arr, int x, int low, int high) {
        if (low > high)
            return -1;

        int mid = (low + high) / 2;
        if (x == arr[mid])
            return mid;
        else if (x < arr[mid]) 
            return recBinarySearch(arr, x, low, mid-1);
        else 
            return recBinarySearch(arr, x, mid+1, high);
    }
}