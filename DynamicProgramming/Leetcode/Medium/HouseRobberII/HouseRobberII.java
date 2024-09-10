// https://leetcode.com/problems/house-robber-ii/description/
import java.util.Arrays;

public class HouseRobberII {
    // TABULATION
    public int rob(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        int prev1 = nums[0], prev2 = 0;
        // start from robbing the first house not going till the end
        for (int i = 1; i < nums.length - 1; i++) {
            int take = nums[i] + prev2;
            int notTake = prev1;
            prev2 = prev1;
            prev1 = Math.max(take, notTake);
        }
        int rob1 = prev1;
        prev2 = prev1 = 0;
        for (int i = 1; i < nums.length; i++) {
            int take = nums[i] + prev2;
            int notTake = prev1;
            prev2 = prev1;
            prev1 = Math.max(take, notTake);
        }
        return Math.max(rob1, prev1);
    }
    // MEMOIZATION
    int jump(int[] nums, int n, boolean robbedFirst, int dpRobbed[], int dpLeft[]) {
        if(n == 0) {
            if(robbedFirst) return 0;
            return nums[0];
        }
        if(n < 0) {
            return 0;
        }
        if(robbedFirst && dpRobbed[n] != -1) {
            return dpRobbed[n];
        } else if(dpLeft[n] != -1) {
            return dpLeft[n];
        }
        int r = 0, l = 0;
        if(n == nums.length - 1) {
            // rob
            r = nums[n] + jump(nums, n - 2, true, dpRobbed, dpLeft);
            // leave
            l = jump(nums, n - 1, false, dpRobbed, dpLeft);
            return Math.max(l, r);
        } else {
            // rob
            r = nums[n] + jump(nums, n - 2, robbedFirst, dpRobbed, dpLeft);
            // leave
            l = jump(nums, n - 1, robbedFirst, dpRobbed, dpLeft);
        }
        if(robbedFirst) {
            dpRobbed[n] = Math.max(l, r);
            return dpRobbed[n];
        } else {
            dpLeft[n] = Math.max(l, r);
            return dpLeft[n];
        }
    }
    public int rob2(int[] nums) {
        if(nums.length == 0) {
            return 0;
        }
        if(nums.length == 1) {
            return nums[0];
        }
        int dpRobbed[] = new int[nums.length];
        int dpLeft[] = new int[nums.length];
        Arrays.fill(dpRobbed, -1);
        Arrays.fill(dpLeft, -1);
        return jump(nums, nums.length - 1, false, dpRobbed, dpLeft);
    }
}
