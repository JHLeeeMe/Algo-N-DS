package recursion;

public class Factorial {
    public static void main(String[] args) {
        int n1 = factorial(5);
        System.out.println(n1);

        int n2 = factorialTR(5);
        System.out.println(n2);
    }

    static int factorial(int i) {
        // base case
        if (i == 0)
            return 1;
        
        return i * factorial(i-1);
    }

    // wrapper over factorial2
    static int factorialTR(int n) {
        return factorial2(n, 1);
    }

    // tailrec
    static int factorial2(int i, int result) {
        // base case
        if (i == 0)
            return result;

        return factorial2(i-1, result * i);
    }
}