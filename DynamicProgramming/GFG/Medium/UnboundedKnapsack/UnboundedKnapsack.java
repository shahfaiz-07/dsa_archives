// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

import java.util.Arrays;

public class UnboundedKnapsack {
    // MEMOIZATION
    static int maximize(int val[], int wt[], int i, int w, int[][] dp) {
        if(i == 0) {
            if(w >= wt[0]) {
                return (w/wt[0])*val[0];
            }
            return 0;
        }
        if(dp[i][w] != -1) {
            return dp[i][w];
        }
        int pick = 0;
        if(w - wt[i] >= 0) {
            pick = maximize(val, wt, i, w-wt[i], dp) + val[i];
        }
        int notPick = maximize(val, wt, i-1, w, dp);
        dp[i][w] = Math.max(pick, notPick);
        return dp[i][w];
    }
    static int knapSack1(int N, int W, int val[], int wt[])
    {
        // code here
        int dp[][] = new int[N][W + 1];
        for(int i=0; i<N; i++) {
            Arrays.fill(dp[i], -1);
        }
        return maximize(val, wt, N-1, W, dp);
    }

    // TABULATION
    static int knapSack(int N, int W, int val[], int wt[]) {
        // code here
        int dp[][] = new int[N][W + 1];
        for (int w = 0; w <= W; w++) {
            if (w >= wt[0]) {
                dp[0][w] = (w / wt[0]) * val[0];
            }
        }
        for (int i = 1; i < N; i++) {
            for (int w = 1; w <= W; w++) {
                int pick = 0;
                if (w - wt[i] >= 0) {
                    pick = dp[i][w - wt[i]] + val[i];
                }
                int notPick = dp[i - 1][w];
                dp[i][w] = Math.max(pick, notPick);
            }
        }
        return dp[N - 1][W];
    }
}
