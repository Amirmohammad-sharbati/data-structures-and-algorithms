import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        long sumPInStack = 0;

        for (int k = 0; k < q; k++) {
            int n = sc.nextInt();
            long[] h = new long[n];
            long[] p = new long[n];
            long[] s = new long[n];
            long[] x = new long[n]; // x is the sum of power of people who can attack soldier.

            for (int i = 0; i < n; i++) {
                h[i] = sc.nextLong();
                s[i] = sc.nextLong();
                p[i] = sc.nextLong();
                x[i] = 0;
            }

            Deque<Integer> stack = new ArrayDeque<>(); // Stack to keep track of soldiers
            for (int i = 0; i < n; i++) { // First iteration from left to right
                x[i] += sumPInStack; // All soldiers in stack attack this soldier

                while (!stack.isEmpty() && h[stack.peekLast()] < h[i]) {
                    sumPInStack -= p[stack.peekLast()];
                    stack.pollLast(); // Pop soldiers that are shorter
                }

                stack.addLast(i);
                sumPInStack += p[i];
            }

            stack.clear();
            sumPInStack = 0;

            for (int i = n - 1; i >= 0; i--) { // Second iteration from right to left
                x[i] += sumPInStack;

                while (!stack.isEmpty() && h[stack.peekLast()] < h[i]) {
                    sumPInStack -= p[stack.peekLast()];
                    stack.pollLast(); // Pop soldiers that are shorter
                }

                stack.addLast(i);
                sumPInStack += p[i];
            }

            stack.clear();
            sumPInStack = 0;

            for (int i = 0; i < n; i++) {
                double result = Math.ceil((double) s[i] / (double) x[i]);
                System.out.print((long) result + " ");
            }
            System.out.println();
        }
    }
}
