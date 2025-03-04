// https://leetcode.com/problems/maximum-subarray/

public class MaximumSubarray {
    public int maxSubArray(int[] nums) {
        int s = 0, maxSum = 0, maxNeg = Integer.MIN_VALUE;
        for (int num : nums) {
            s += num;
            if (s <= 0) {
                maxNeg = Math.max(s, maxNeg);
                s = 0;
            }
            maxSum = Math.max(maxSum, s);
        }
        return maxSum == 0 ? maxNeg : maxSum;
    }
}