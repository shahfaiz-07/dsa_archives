// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

public class BestTimetoBuyandSellStockII {

    // MEMOIZATION
    int recurse(int ind, int buy, int[] prices, int[][] dp) {
        // 1- buy, 0- not buy
        if(ind == prices.length) {
            return 0;
        }
        if(dp[ind][buy] != 0) return dp[ind][buy];
        int p = 0;
        if(buy == 1) {
            p = Math.max(-prices[ind] + recurse(ind+1, 0, prices, dp), recurse(ind+1, 1, prices, dp));
        }
        else
        p= Math.max(prices[ind] + recurse(ind + 1, 1, prices, dp), recurse(ind+1, 0, prices, dp));

        dp[ind][buy] = p;
        return p;
    }
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][] dp = new int[n][2];
        return recurse(0, 1, prices, dp);
    }

    // TABULATION
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][] dp = new int[n+1][2];

        for(int ind=n-1; ind>=0; ind--) {
            dp[ind][0] = Math.max(prices[ind] + dp[ind + 1][1], dp[ind+1][0]);
            dp[ind][1] = Math.max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
        }
        return dp[0][1];
    }
}