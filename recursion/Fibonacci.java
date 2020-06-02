package recursion;

/**
 * Fibonacci
 * 0, 1, 1, 2, 3, 5, 8, ...
 */
public class Fibonacci {
    public static void main(String[] args) {
        int a = fibonacci(5);
        System.out.println(a);

        int b = fibonacciTR(5);
        System.out.println(b);
    }

    static int fibonacci(int n) {
        if (n <= 1)
            return n;
        
        return fibonacci(n-2) + fibonacci(n-1);
    }

    // wrapper over fibonacci2
    static int fibonacciTR(int n) {
        return fibonacci2(n, 0, 1);
    }

    // tail recursion
    static int fibonacci2(int n, int a, int b) {
        if (n == 0)
            return a;
        if (n == 1)
            return b;
        
        return fibonacci2(n-1, b, a + b);
    }
}