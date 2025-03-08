// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

import java.util.HashMap;
import java.util.Map;

public class LongestSubarrayWithSum0 {

    int maxLen(int arr[]) {
        // code here
        Map<Integer, Integer> hash = new HashMap<>();
        hash.put(0, -1);
        int sum = 0, maxLen = 0;
        for(int i=0; i<arr.length; i++) {
            sum += arr[i];
            int val = hash.getOrDefault(sum, -2);
            if(val != -2) {
                maxLen = Math.max(maxLen, i - val);
            }
            hash.putIfAbsent(sum, i);
        }
        return maxLen;
    }
}