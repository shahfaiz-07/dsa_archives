// https://www.geeksforgeeks.org/problems/graph-and-vertices/1
public class GraphsWithNVertex {
    static long count(int n) {
        long ans = (long) Math.pow(2, n * (n - 1) / 2);
        return ans;
    }
    public static void main(String[] args) {
        System.out.println(count(5));
    }
}