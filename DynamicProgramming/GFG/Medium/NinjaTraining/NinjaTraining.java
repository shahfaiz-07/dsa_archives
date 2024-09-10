// https://www.geeksforgeeks.org/problems/geeks-training/1
public class NinjaTraining {
    // TABULATION - Space Optimized = O(4) + O(4) -> temp
    public int maximumPoints(int arr[][], int N) {
        // code here
        if (N == 0) {
            return 0;
        }
        int dp[] = new int[4];
        dp[0] = Math.max(arr[0][1], arr[0][2]);
        dp[1] = Math.max(arr[0][0], arr[0][2]);
        dp[2] = Math.max(arr[0][1], arr[0][0]);
        dp[3] = Math.max(arr[0][0], Math.max(arr[0][1], arr[0][2]));
        for (int k = 1; k < N; k++) {
            int dp1[] = new int[4];
            for (int prevInd = 0; prevInd <= 3; prevInd++) {
                for (int i = 0; i <= 2; i++) {
                    if (prevInd != i) {
                        int j = dp[i] + arr[k][i];
                        dp1[prevInd] = Math.max(dp1[prevInd], j);
                    }
                }
            }
            for (int c = 0; c <= 3; c++) {
                dp[c] = dp1[c];
            }
        }
        return dp[3];
    }
    // TABULATION - Space = O(N*4)
    public int maximumPointsX(int arr[][], int N) {
        // code here
        if (N == 0) {
            return 0;
        }
        int dp[][] = new int[N][4];
        dp[0][0] = Math.max(arr[0][1], arr[0][2]);
        dp[0][1] = Math.max(arr[0][0], arr[0][2]);
        dp[0][2] = Math.max(arr[0][1], arr[0][0]);
        dp[0][3] = Math.max(arr[0][0], Math.max(arr[0][1], arr[0][2]));
        for (int k = 1; k < N; k++) {
            for (int prevInd = 0; prevInd <= 3; prevInd++) {
                dp[k][prevInd] = 0;
                for (int i = 0; i <= 2; i++) {
                    if (prevInd != i) {
                        int j = dp[k - 1][i] + arr[k][i];
                        dp[k][prevInd] = Math.max(dp[k][prevInd], j);
                    }
                }
            }
        }
        return dp[N - 1][3];
    }
    // MEMOIZATION - Stack Overflow
    private int maxOf(int arr[][], int n, int prevInd, int[][] dp) {
        if (n < 0) {
            return 0;
        }
        if (dp[n][prevInd] != 0) {
            return dp[n][prevInd];
        }
        int max = Integer.MIN_VALUE;
        for (int i = 0; i <= 2; i++) {
            if (prevInd != i) {
                int j = maxOf(arr, n - 1, i, dp) + arr[n][i];
                if (j > max) {
                    max = j;
                }
            }
        }
        dp[n][prevInd] = max;
        return max;
    }
    public int maximumPoints2(int arr[][], int N) {
        // code here
        int dp[][] = new int[N][4];
        return maxOf(arr, N - 1, 3, dp);
    }
}
