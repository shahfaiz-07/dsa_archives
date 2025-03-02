// https://leetcode.com/problems/house-robber-ii/description/
import java.util.Arrays;

public class HouseRobberII {
    // SPACE-OPTIMIZED
    public int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        // flag 1 means we rob the first house so can't rob the last, stored in dp[1]
        int[][] dp = new int[2][2];
        dp[0][1] = nums[1];
        dp[1][0] = nums[0];
        dp[1][1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < nums.length; i++) {
            int curr0 = Math.max(nums[i] + dp[0][0], dp[0][1]);
            dp[0][0] = dp[0][1];
            dp[0][1] = curr0;
            if (i < nums.length - 1) {
                int curr1 = Math.max(nums[i] + dp[1][0], dp[1][1]);
                dp[1][0] = dp[1][1];
                dp[1][1] = curr1;
            }
        }

        return Math.max(dp[0][1], dp[1][1]);
    }
    // TABULATION
    public int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        // flag 1 means we rob the first house so can't rob the last, stored in dp[1]
        int[][] dp = new int[2][nums.length];
        dp[0][1] = nums[1];
        dp[1][0] = nums[0];
        dp[1][1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < nums.length; i++) {
            dp[0][i] = Math.max(nums[i] + dp[0][i - 2], dp[0][i - 1]);
            if (i < nums.length - 1) {
                dp[1][i] = Math.max(nums[i] + dp[1][i - 2], dp[1][i - 1]);
            }
        }

        return Math.max(dp[0][nums.length - 1], dp[1][nums.length - 2]);
    }
    // MEMOIZATION
    int memoize(int[] nums, int i, int dp[][], int flag) {
        // flag 1 means you robbed nth house and can't rob 0th house, you have to go till first
        // flag 0 means you didn't rob nth house and can go till 0th house
        if (i < flag) {
            return 0; // for flag 1 we return 0 when i becomes 0
        }

        if (dp[flag][i] != -1) {
            return dp[flag][i];
        }

        dp[flag][i] = Math.max(nums[i] + memoize(nums, i - 2, dp, flag), memoize(nums, i - 1, dp, flag));
        return dp[flag][i];
    }

    public int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        // flag 1 means we rob the first house so can't rob the second, stored in dp[1]
        int[][] dp = new int[2][nums.length];
        Arrays.fill(dp[0], -1);
        Arrays.fill(dp[1], -1);
        return Math.max(memoize(nums, nums.length - 1, dp, 1), memoize(nums, nums.length - 2, dp, 0));
    }
}
