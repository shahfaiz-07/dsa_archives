// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

import java.util.Arrays;

public class BestTimetoBuyandSellStockIII {

    // MEMOIZATION
    int maximize(int ind, int buy, int cap, int[] prices, int [][][] dp) {
        if(ind == prices.length) {
            return 0;
        }
        if(dp[cap][buy][ind] != -1) {
            return dp[cap][buy][ind];
        }
        int price = 0;
        if(buy == 1) { 
            int y = maximize(ind + 1, 1, cap, prices, dp);
            price = cap > 0 ? Math.max( -prices[ind] + maximize(ind + 1, 0, cap - 1, prices, dp), y) : y;
        } else {
            price = Math.max(prices[ind] + maximize(ind + 1, 1, cap, prices, dp), maximize(ind + 1, 0, cap, prices, dp));
        }
        dp[cap][buy][ind] = price;
        return price;
    }
    public int maxProfit(int[] prices) {
        int dp[][][] = new int[3][2][prices.length];
        for(int i=0; i<3; i++) {
            Arrays.fill(dp[i][0], -1);
            Arrays.fill(dp[i][1], -1);
        }
        return maximize(0, 1, 2, prices, dp);
    }

    // TABULATION
    public int maxProfit(int[] prices) {
        int dp[][][] = new int[3][2][prices.length + 1];

        for(int cap=0; cap<3; cap++) {
            for(int buy=1; buy>=0; buy--) {
                for(int ind=prices.length-1; ind>=0; ind--) {
                    int price = 0;
        if(buy == 1) { 
            int y = dp[cap][1][ind + 1];
            price = cap > 0 ? Math.max( -prices[ind] + dp[cap - 1][0][ind + 1], y) : y;
        } else {
            price = Math.max(prices[ind] + dp[cap][1][ind + 1], dp[cap][0][ind + 1]);
        }
        dp[cap][buy][ind] = price;
                }
            }
        }
        return (dp[2][1][0]);
    }
}