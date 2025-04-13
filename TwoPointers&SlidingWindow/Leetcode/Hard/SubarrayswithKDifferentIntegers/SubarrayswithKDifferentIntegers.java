// https://leetcode.com/problems/subarrays-with-k-different-integers/
import java.util.HashMap;
import java.util.Map;
public class SubarrayswithKDifferentIntegers {

    public int subarraysWithKDistinct(int[] nums, int k) {
        return (subarraysWithAtmostKDistinct(nums, k) - subarraysWithAtmostKDistinct(nums, k - 1));
    }
    int subarraysWithAtmostKDistinct(int[] nums, int k) {
        int l = 0, r = 0, ans = 0;
        Map<Integer, Integer> mp = new HashMap<>();
        while(r < nums.length) {
            mp.compute(nums[r], (key, v) -> v == null ? 1 : v + 1);
            while(mp.size() > k) {
                if(mp.compute(nums[l], (key, v) -> v - 1) == 0) {
                    mp.remove(nums[l]);
                }
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
}