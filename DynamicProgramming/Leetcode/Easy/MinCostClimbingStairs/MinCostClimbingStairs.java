// https://leetcode.com/problems/min-cost-climbing-stairs/

import java.util.Arrays;

public class MinCostClimbingStairs {
    // MEMOIZATION
    int memoize(int i, int[] cost, int[] dp) {
        if(i >= cost.length) {
            return 0;
        }
        if(dp[i] != -1) return dp[i];

        dp[i] = cost[i] + Math.min(memoize(i + 1, cost, dp), memoize(i + 2, cost, dp));
        return dp[i];
    }
    public int minCostClimbingStairs(int[] cost) {
        int dp[] = new int[cost.length];
        Arrays.fill(dp, -1);
        return Math.min(memoize(0, cost, dp), memoize(1, cost, dp));
        
    }
    // TABULATION
    public int minCostClimbingStairs(int[] cost) {
        int dp[] = new int[cost.length];
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < cost.length; i++) {
            dp[i] = cost[i] + Math.min(dp[i - 1], dp[i - 2]);
        }

        return Math.min(dp[cost.length - 1], dp[cost.length - 2]);
    }
    // SPACE OPTIMIZED
    public int minCostClimbingStairs(int[] cost) {
        int prev_1 = cost[1], prev_2 = cost[0], curr = cost[1];

        for (int i = 2; i < cost.length; i++) {
            curr = cost[i] + Math.min(prev_1, prev_2);
            prev_2 = prev_1;
            prev_1 = curr;
        }

        return Math.min(curr, prev_2);
    }
}
