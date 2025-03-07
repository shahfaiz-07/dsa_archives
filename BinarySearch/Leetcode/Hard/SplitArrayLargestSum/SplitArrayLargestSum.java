// https://leetcode.com/problems/split-array-largest-sum/

public class SplitArrayLargestSum {
    public int splitArray(int[] nums, int k) {
        int l = 0, r = 0;
        for (int ele : nums) {
            l = Math.max(l, ele);
            r += ele;
        }
        int ans = r;
        while (l <= r) {
            int m = (l + r) / 2;
            int s = 0, arr = 1;
            boolean can = true;
            for (int ele : nums) {
                if (s + ele > m) {
                    arr++;
                    if (arr > k) {
                        can = false;
                        break;
                    }
                    s = ele;
                } else {
                    s += ele;
                }
            }
            if (can) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
}
