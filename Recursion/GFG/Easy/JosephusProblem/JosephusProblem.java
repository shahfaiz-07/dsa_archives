// https://www.geeksforgeeks.org/problems/josephus-problem/1

public class JosephusProblem {
    int jp(int n, int k) {
        if(n == 1) return 0;
        return (jp(n - 1, k) + k) % n;
    }
    public int josephus(int n, int k) {
        // code here
        return jp(n, k) + 1;
    }
}
