// https://leetcode.com/problems/subarray-sum-equals-k/

import java.util.HashMap;
import java.util.Map;

public class SubarraySumEqualsK {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> hash = new HashMap<>();
        int sum = 0, c = 0;
        hash.put(0, 1);
        for(int ele: nums) {
            sum += ele;
            int x_k = sum - k;
            int val = hash.getOrDefault(x_k, 0);
            if(val != 0) {
                c += val;
            }
            hash.compute(sum, (key, v) -> v == null ? 1 : v + 1);
        }
        return c;
    }
}
