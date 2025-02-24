// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

public class BestTimeToBuySellStocks {
    public int maxProfit(int[] prices) {
        int l = 0, r = 1;
        int maxProfit = 0;
        while (r < prices.length) {
            if (prices[l] < prices[r]) {
                int profit = prices[r] - prices[l];
                maxProfit = Math.max(profit, maxProfit);
            } else {
                l = r;
            }
            r += 1;
        }
        return maxProfit;
    }
}
