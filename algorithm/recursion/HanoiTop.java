package algorithm.recursion;

/**
 * HanoiTop
 */
public class HanoiTop {
    public static void main(String[] args) {
        hanoi(4, 1, 3, 2);
    }

    public static void hanoi(int n, int from, int to, int via) {
        // base case
        if (n == 1) {
            System.out.println(1 + " is " + from + " -> " + to);
            return;
        }

        hanoi(n-1, from, via, to);
        System.out.println(n + " is " + from + " -> " + to);
        hanoi(n-1, via, to, from);
    }
}
