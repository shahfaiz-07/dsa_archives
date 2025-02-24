// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

public class FindMinInRotatedSortedArray {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        int minVal = nums[0];
        while (l <= r) {
            int m = r - (r - l) / 2;
            if (nums[m] < minVal) {
                minVal = nums[m];
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return minVal;
    }
}
