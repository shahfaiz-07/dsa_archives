// https://www.geeksforgeeks.org/problems/rod-cutting0840/1

import java.util.Arrays;

public class RodCutting {
    // MEMOIZATION
    int maximize(int price[], int index, int L, int dp[][]) {
        if(index == 0) {
            return L*price[0];
        }
        if(dp[index][L] != -1) {
            return dp[index][L];
        }
        int cut = 0;
        if(L >= index + 1) {
            cut = maximize(price, index, L - (index + 1), dp) + price[index];
        }
        int notCut = maximize(price, index - 1, L, dp);
        dp[index][L] = Math.max(cut, notCut);
        return dp[index][L];
    }
    public int cutRod1(int price[], int n) {
        //code here
        int dp[][] = new int[n][n + 1];
        for(int i=0; i<n; i++) {
            Arrays.fill(dp[i], -1);
        }
        
        return maximize(price, n-1, n, dp);
    }
    // TABULATION
    public int cutRod(int price[], int n) {
        //code here
        int dp[][] = new int[n][n + 1];
        for (int i = 1; i <= n; i++) {
            dp[0][i] = i * price[0];
        }

        for (int index = 1; index < n; index++) {
            for (int L = 1; L <= n; L++) {
                int cut = 0;
                if (L >= index + 1) {
                    cut = dp[index][L - (index + 1)] + price[index];
                }
                int notCut = dp[index - 1][L];
                dp[index][L] = Math.max(cut, notCut);
            }
        }
        return dp[n - 1][n];
    }
}
