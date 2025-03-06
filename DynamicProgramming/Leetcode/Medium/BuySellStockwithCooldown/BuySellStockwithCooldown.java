// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
import java.util.Arrays;

public class BuySellStockwithCooldown {

    int profit(int i, int[] prices, int canBuy, int[][] dp) {
        if(i >= prices.length) return 0;
        if(dp[i][canBuy] != -1) return dp[i][canBuy];
        int cooldown = profit(i + 1, prices, canBuy, dp);
        if(canBuy == 1) {
            int bought = profit(i + 1, prices, canBuy - 1, dp) - prices[i];
            return dp[i][canBuy] = Math.max(cooldown, bought);
        }
        int sold = profit(i + 2, prices, canBuy + 1, dp) + prices[i];
        return dp[i][canBuy] = Math.max(cooldown, sold);
    }
    public int maxProfit(int[] prices) {
        int[][] dp = new int[prices.length][2];
        for(int i=0; i<prices.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        return profit(0, prices, 1, dp);
    }
}