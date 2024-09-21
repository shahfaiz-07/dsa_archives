// https://leetcode.com/problems/partition-equal-subset-sum/
public class PartEqualSubsetSum {
    boolean partSum(int[] nums, int index, int target, int[][] dp) {
        if (target == 0) {
            return true;
        }
        if (index < 0 || target < 0) {
            return false;
        }
        if (dp[index][target] != 0) {
            return dp[index][target] == 1;
        }
        if (partSum(nums, index - 1, target - nums[index], dp)
                || partSum(nums, index - 1, target, dp)) {
            dp[index][target] = 1;
            return true;
        }
        dp[index][target] = -1;
        return false;
    }

    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int ele : nums) {
            sum += ele;
        }
        if ((sum & 1) == 1) {
            return false;
        }
        int dp[][] = new int[nums.length][sum / 2 + 1];
        return partSum(nums, nums.length - 1, sum / 2, dp);
    }
}
