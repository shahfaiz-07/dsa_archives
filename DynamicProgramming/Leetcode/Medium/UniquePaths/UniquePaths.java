// https://leetcode.com/problems/unique-paths/
public class UniquePaths {
    // TABULATION - Space Optimized = O(N)
    public int uniquePaths(int m, int n) {
        if (m == 1 && n == 1) {
            return 1;
        }
        int dp[] = new int[n];
        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            int dp1[] = new int[n];
            dp1[0] = 1;
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int t = 0;
                if (i > 0) {
                    t = dp[j];
                }
                int l = 0;
                if (j > 0) {
                    l = dp1[j - 1];
                }
                dp1[j] = t + l;
            }
            dp = dp1;
        }
        return dp[n - 1];
    }
    // TABULATION - Space = O(M*N) - Works better ???
    public int uniquePaths1(int m, int n) {
        if (m == 1 && n == 1) {
            return 1;
        }
        int dp[][] = new int[m][n];
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int t = 0;
                if (i > 0) {
                    t = dp[i - 1][j];
                }
                int l = 0;
                if (j > 0) {
                    l = dp[i][j - 1];
                }
                dp[i][j] = t + l;
            }
        }
        return dp[m - 1][n - 1];
    }
    // MEMOIZATION
    private int move(int m, int n, int[][] dp) {
        if(m == 0 && n == 0) {
            return 1;
        }
        if(dp[m][n] != 0) {
            return dp[m][n];
        }
        int t = 0;
        if(m > 0)
            t = move(m-1, n, dp);
        int l = 0;
        if(n > 0)
            l = move(m, n-1, dp);
        dp[m][n] = t+l;
        return dp[m][n];
    }
    public int uniquePaths2(int m, int n) {
        int dp[][] = new int[m][n];
        return move(m - 1, n - 1, dp);
    }
}
