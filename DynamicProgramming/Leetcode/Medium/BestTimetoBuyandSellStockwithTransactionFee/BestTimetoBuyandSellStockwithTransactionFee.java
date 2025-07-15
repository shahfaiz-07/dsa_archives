// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

import java.util.Arrays;

public class BestTimetoBuyandSellStockwithTransactionFee {

    // MEMOIZATION
    int maximize(int ind, int[] prices, int fee, int buy, int[][] dp) {
        if(ind == prices.length) return 0;
        if(dp[buy][ind] != -1) return dp[buy][ind];
        int profit = 0;
        if(buy == 1) {
            profit = Math.max(-prices[ind] - fee + maximize(ind+1, prices, fee, 0, dp), maximize(ind+1, prices, fee, 1, dp));
        } else {
            profit = Math.max(prices[ind] + maximize(ind + 1, prices, fee, 1, dp), maximize(ind + 1, prices, fee, 0, dp));
        }
        dp[buy][ind] = profit;
        return profit;
    }
    public int maxProfit(int[] prices, int fee) {
        int[][] dp = new int[2][prices.length];
        Arrays.fill(dp[0], -1);
        Arrays.fill(dp[1], -1);
        return maximize(0, prices, fee, 1, dp);
    }

    // TABULATION
    public int maxProfit(int[] prices, int fee) {
        int[][] dp = new int[2][prices.length + 1];
        for(int ind=prices.length-1; ind>=0; ind--) {
            for(int buy=1; buy>=0; buy--) {
                int profit = 0;
        if(buy == 1) {
            profit = Math.max(-prices[ind] - fee + dp[0][ind+1], dp[1][ind+1]);
        } else {
            profit = Math.max(prices[ind] + dp[1][ind+1], dp[0][ind+1]);
        }
        dp[buy][ind] = profit;
            }
        }
        return dp[1][0];
    }
}