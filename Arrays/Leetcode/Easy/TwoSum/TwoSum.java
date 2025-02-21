// https://leetcode.com/problems/two-sum/
import java.util.HashMap;
import java.util.Map;

public class TwoSum {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mp = new HashMap<>();

        for(int i=0; i<nums.length; i++) {
            int t = mp.getOrDefault(target - nums[i], -1);
            if(t != -1) {
                return new int[]{i, t};
            } else {
                mp.put(nums[i], i);
            }
        }
        return new int[]{};
    }
}
