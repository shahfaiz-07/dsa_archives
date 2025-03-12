// https://leetcode.com/problems/next-greater-element-i/

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;

public class NextGreaterElement {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Deque<Integer> st = new ArrayDeque<>();
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i=nums2.length - 1; i>=0; i--) {
            while(!st.isEmpty() && st.peek() <= nums2[i]) {
                st.pop();
            }
            if(st.isEmpty()) {
                mp.put(nums2[i], -1);
            } else {
                mp.put(nums2[i], st.peek());
            }
            st.push(nums2[i]);
        }
        for(int i=0; i<nums1.length; i++) {
            nums1[i] = mp.get(nums1[i]);
        }
        return nums1;
    }
}
