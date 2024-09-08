
import java.util.Arrays;

public class ClimbingStairs {
    // Tabulation
    public static int climbStairs(int n) {
        if (n <= 1) {
            return n;
        }
        int n1 = 0, n2 = 1, ways = 0;
        for (int i = 1; i <= n; i++) {
            ways = n1 + n2;
            n1 = n2;
            n2 = ways;
        }
        return ways;
    }

    // Memoization
    private int climb(int n, int[] dp) {
        if (n <= 2) {
            return n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        dp[n] = climb(n - 1, dp) + climb(n - 2, dp);
        return dp[n];
    }

    public int climbStairs2(int n) {
        int dp[] = new int[n + 1];
        Arrays.fill(dp, -1);
        return climb(n, dp);
    }

    public static void main(String[] args) {
        System.out.println(climbStairs(10));
    }
}
