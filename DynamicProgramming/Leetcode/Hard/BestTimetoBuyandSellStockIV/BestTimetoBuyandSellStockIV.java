// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

import java.util.Arrays;

public class BestTimetoBuyandSellStockIV {

    // MEMOIZATION
    int maximize(int k, int ind, int []prices, int buy, int[][][] dp) {
        if(ind == prices.length) return 0;
        if(dp[k][buy][ind] != -1) return dp[k][buy][ind];
        int profit = 0;
        if(buy == 1) {
            int x = maximize(k, ind+1, prices, 1, dp);
            profit = k>0 ? Math.max(-prices[ind] +maximize(k-1, ind+1, prices, 0, dp), x) : x;
        } else {
            profit = Math.max(prices[ind] + maximize(k, ind+1, prices, 1, dp), maximize(k, ind+1, prices, 0, dp));
        }
        dp[k][buy][ind] = profit;
        return profit;
    }
    public int maxProfit(int k, int[] prices) {
        int[][][] dp = new int[k+1][2][prices.length];
        for(int i=0; i<=k; i++) {
            Arrays.fill(dp[i][0], -1);
            Arrays.fill(dp[i][1], -1);
        }
        return maximize(k, 0, prices, 1, dp);
    }
    // TABULATION
    public int maxProfit(int k, int[] prices) {
        int[][][] dp = new int[k+1][2][prices.length + 1];
        for(int k1=0; k1<=k; k1++) {
            for(int buy=1; buy>=0; buy--) {
                for(int ind=prices.length-1; ind>=0; ind--) {
                    int profit= 0;
                    if(buy == 1) {
            int x = dp[k1][1][ind + 1];
            profit = k1>0 ? Math.max(-prices[ind] + dp[k1-1][0][ind+1], x) : x;
        } else {
            profit = Math.max(prices[ind] + dp[k1][1][ind+1], dp[k1][0][ind + 1]);
        }
        dp[k1][buy][ind] = profit;
                }
            }
    
        }
        return dp[k][1][0];
    }
}