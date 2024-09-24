// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
public class SmallestDivisor {
    int findSumDiv(int[] nums, double k) {
        int sum = 0;
        for (int ele : nums) {
            sum += (int) Math.ceil(ele / k);
        }
        return sum;
    }

    public int smallestDivisor(int[] nums, int threshold) {
        int u = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (u < nums[i]) {
                u = nums[i];
            }
        }
        int l = 1;
        while (l <= u) {
            int m = u - (u - l) / 2;
            int sum = findSumDiv(nums, m);

            if (sum <= threshold) {
                u = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
}