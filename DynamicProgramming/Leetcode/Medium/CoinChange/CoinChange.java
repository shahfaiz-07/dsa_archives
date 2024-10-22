// https://leetcode.com/problems/coin-change/
public class CoinChange {
    // MEMOIZATION
    int minCoins(int[] coins, int amount, int[] dp) {
        if (amount == 0) {
            return 0;
        }
        if (dp[amount] != 0) {
            return dp[amount];
        }
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < coins.length; i++) {
            if (amount - coins[i] >= 0) {
                int val = minCoins(coins, amount - coins[i], dp);
                if (val != Integer.MAX_VALUE && val + 1 < min) {
                    min = val + 1;
                }
            }
        }
        dp[amount] = min;
        return min;
    }

    public int coinChange1(int[] coins, int amount) {
        int dp[] = new int[amount + 1];
        int ret = minCoins(coins, amount, dp);
        if (ret == Integer.MAX_VALUE) {
            return -1;
        }
        return ret;
    }
    // TABULATION
    public int coinChange(int[] coins, int amount) {
        int dp[] = new int[amount + 1];
        for (int j = 1; j <= amount; j++) {
            int min = Integer.MAX_VALUE;
            for (int i = 0; i < coins.length; i++) {
                if (j - coins[i] >= 0) {
                    int val = dp[j - coins[i]];
                    if (val != Integer.MAX_VALUE && val + 1 < min) {
                        min = val + 1;
                    }
                }
            }
            dp[j] = min;
        }
        return dp[amount] == Integer.MAX_VALUE ? -1 : dp[amount];
    }
}
