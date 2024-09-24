// https://leetcode.com/problems/find-peak-element/
public class PeakIn1D {
    public int findPeakElement(int[] nums) {
        int l = 0, u = nums.length - 1;
        if (nums.length == 1) {
            return 0;
        }
        while (l <= u) {
            int mid = u - (u - l) / 2;
            int left = mid == 0 ? Integer.MIN_VALUE : nums[mid - 1];
            int right = mid == nums.length - 1 ? Integer.MIN_VALUE : nums[mid + 1];
            if (nums[mid] >= left && nums[mid] >= right) {
                return mid;
            } else if (nums[mid] > left) {
                l = mid + 1;
            } else {
                u = mid - 1;
            }
        }
        return -1;
    }
}
