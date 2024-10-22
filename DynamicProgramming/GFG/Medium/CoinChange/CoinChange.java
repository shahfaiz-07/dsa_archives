// https://www.geeksforgeeks.org/problems/number-of-coins1824/1
public class CoinChange {
    int minimumCoins(int coins[], int sum, int[] dp) {
        if (sum == 0) {
            return 0;
        }
        if (dp[sum] != 0) {
            return dp[sum];
        }
        int mini = Integer.MAX_VALUE;
        for (int i = 0; i < coins.length; i++) {
            if (sum - coins[i] >= 0) {
                int val = minimumCoins(coins, sum - coins[i], dp);
                if (val != Integer.MAX_VALUE && val < mini) {
                    mini = val + 1;
                }
            }
        }
        return dp[sum] = mini;
    }

    public int minCoins(int coins[], int M, int sum) {
        // Your code goes here
        int dp[] = new int[sum + 1];
        int ret = minimumCoins(coins, sum, dp);
        return ret == Integer.MAX_VALUE ? -1 : ret;
    }
}