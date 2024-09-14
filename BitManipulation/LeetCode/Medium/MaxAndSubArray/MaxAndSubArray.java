// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
public class MaxAndSubArray {
    public int longestSubarray(int[] nums) {
        int max = nums[0], maxL = 1, l = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > max) {
                max = nums[i];
                l = 1;
                maxL = 1;
            } else if (nums[i] == max) {
                l++;
                if (l > maxL) {
                    maxL = l;
                }
            } else {
                l = 0;
            }
        }
        return maxL;
    }
}
