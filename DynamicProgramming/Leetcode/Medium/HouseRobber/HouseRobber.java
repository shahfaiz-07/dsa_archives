// https://leetcode.com/problems/house-robber/

import java.util.Arrays;

public class HouseRobber {
    // TABULATION
    public int rob(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        int prev1 = nums[0], prev2 = 0;
        for (int i = 1; i < nums.length; i++) {
            int take = nums[i] + prev2;
            int notTake = prev1;
            prev2 = prev1;
            prev1 = Math.max(take, notTake);
        }
        return prev1;
    }
    // MEMOIZATION
    int jump(int[] nums, int ind, int dp[]) {
        if (ind < 0) {
            return 0;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }
        // rob
        int left = jump(nums, ind - 2, dp) + nums[ind];
        // leave
        int right = jump(nums, ind - 1, dp);
        dp[ind] = Math.max(left, right);
        return dp[ind];
    }
    public int rob2(int[] nums) {
        if(nums.length == 0) {
            return 0;
        }
        if(nums.length == 1) {
            return nums[0];
        }
        int dp[] = new int[nums.length];
        Arrays.fill(dp, -1);
        return jump(nums, 0, dp);
    }
}
