// https://leetcode.com/problems/unique-paths-ii/
public class UniquePathsII {
    // TABULATION - SPACE = O(N) + O(N) --> temp
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) {
            return 0;
        }
        int dp[] = new int[n];
        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            int temp[] = new int[n];
            temp[0] = (dp[0] == 1 && obstacleGrid[i][0] == 0) ? 1 : 0;
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1 || (i == 0 && j == 0)) {
                    continue;
                }
                int t = 0;
                if (i > 0) {
                    t = dp[j];
                }
                int l = 0;
                if (j > 0) {
                    l = temp[j - 1];
                }
                temp[j] = t + l;
            }
            dp = temp;
        }
        return dp[n - 1];
    }
    // TABULATION - SPACE = O(M*N)
    public int uniquePathsWithObstacles2(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) {
            return 0;
        }
        int dp[][] = new int[m][n];
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1 || (i == 0 && j == 0)) {
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
    private int move(int m, int n, int[][] dp, int[][] obstacleGrid) {
        if (m == 0 && n == 0) {
            return 1;
        }
        if (dp[m][n] != 0) {
            return dp[m][n];
        }
        if (obstacleGrid[m][n] == 1) {
            dp[m][n] = 0;
            return 0;
        }
        int t = 0;
        if (m > 0) {
            t = move(m - 1, n, dp, obstacleGrid);
        }
        int l = 0;
        if (n > 0) {
            l = move(m, n - 1, dp, obstacleGrid);
        }
        dp[m][n] = t + l;
        return dp[m][n];
    }

    public int uniquePathsWithObstacles1(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) {
            return 0;
        }
        int dp[][] = new int[m][n];
        return move(m - 1, n - 1, dp, obstacleGrid);
    }
}
