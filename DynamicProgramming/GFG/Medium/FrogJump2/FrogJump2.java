// https://www.geeksforgeeks.org/problems/minimal-cost/1

import java.util.Arrays;

public class FrogJump2 {
    // TABULATION
    public int minimizeCost(int arr[], int k) {
        // code here
        int n = arr.length - 1;
        if (n == 0) {
            return 0;
        }
        int dp[] = new int[n + 1];
        dp[0] = 0;
        dp[1] = Math.abs(arr[1] - arr[0]);
        for (int i = 2; i <= n; i++) {
            int min = Integer.MAX_VALUE;
            for (int j = 1; j <= k && i - j >= 0; j++) {
                int jump = dp[i - j] + Math.abs(arr[i] - arr[i - j]);
                if (jump < min) {
                    min = jump;
                }
            }
            dp[i] = min;
        }
        return dp[n];
    }
    // MEMOIZATION
    int jump(int arr[], int k, int n, int dp[]) {
        if(n == 0) {
            return 0;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        int mini = Integer.MAX_VALUE;
        for(int i=1; i<=k && n-i>=0; i++) {
            int j = jump(arr, k, n-i, dp) + Math.abs(arr[n] - arr[n-i]);
            if(j < mini) {
                mini = j;
            }
        }
        dp[n] = mini;
        return mini;
    }
    public int minimizeCost2(int arr[], int k) {
        // code here
        int dp[] = new int[arr.length];
        Arrays.fill(dp, -1);
        return jump(arr, k, arr.length-1, dp);
    }
}
