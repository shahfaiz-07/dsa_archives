// https://leetcode.com/problems/3sum/description/

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ThreeSum {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < nums.length && nums[i] <= 0; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int l = i + 1, r = nums.length - 1;
            while (l < r) {
                int s = nums[l] + nums[i] + nums[r];
                if (s == 0) {
                    List<Integer> arr = new ArrayList<>();
                    arr.add(nums[l]);
                    arr.add(nums[i]);
                    arr.add(nums[r]);
                    ans.add(arr);
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                } else if (s < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return ans;
    }
}
