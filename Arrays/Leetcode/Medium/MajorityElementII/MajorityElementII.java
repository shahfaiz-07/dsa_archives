// https://leetcode.com/problems/majority-element-ii/

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MajorityElementII {
    // HASHING
    public List<Integer> majorityElement(int[] nums) {
        Map<Integer, Integer> hash = new HashMap<>();
        List<Integer> ans = new ArrayList<>();
        for (int ele : nums) {
            int val = hash.compute(ele, (k, v) -> v == null ? 1 : v + 1);
            if (val == nums.length / 3 + 1) {
                ans.add(ele);
                if (ans.size() == 2) {
                    return ans;
                }
            }
        }
        return ans;
    }
}