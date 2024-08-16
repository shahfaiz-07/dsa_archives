// https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1
public class TowerOfHanoi {
    public static long toh(int n, int from, int to, int aux) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            System.out.println("move disk " + n + " from rod " + from + " to rod " + to);
            return 1;
        }
        if (n > 1) {
            long x = toh(n - 1, from, aux, to) + 1;
            System.out.println("move disk " + n + " from rod " + from + " to rod " + to);
            x += toh(n - 1, aux, to, from);
            return x;
        }
        return 0;
    }
    public static void main(String[] args) {
        System.out.println(toh(3, 1, 2, 3));
    }
}
