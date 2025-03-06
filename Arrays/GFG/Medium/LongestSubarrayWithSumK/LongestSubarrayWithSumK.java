// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

import java.util.HashMap;
import java.util.Map;

public class LongestSubarrayWithSumK {
    public int longestSubarray(int[] arr, int k) {
        // code here
        Map<Integer, Integer> hash = new HashMap<>();
        hash.put(0, -1);
        int sum = 0;
        int maxLen = 0;
        for(int i=0; i<arr.length; i++) {
            sum = sum + arr[i];
            int x_k = sum - k;
            int val = hash.getOrDefault(x_k, -2);
            if(val != -2) {
                int len = i - val;
                maxLen = Math.max(len, maxLen);
            }
            hash.putIfAbsent(sum, i);
        }
        return maxLen;
    }
}
