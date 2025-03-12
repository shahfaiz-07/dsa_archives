// https://leetcode.com/problems/next-greater-element-ii/

import java.util.ArrayDeque;
import java.util.Deque;

public class NextGreaterElementII {
    public int[] nextGreaterElements(int[] nums) {
        Deque<Integer> st = new ArrayDeque<>();
        for(int i=nums.length - 1; i>=0; i--) {
            while(!st.isEmpty() && st.peek() <= nums[i]) {
                st.pop();
            }
            st.push(nums[i]);
        }
        int[] ans = new int[nums.length];
        for(int i=nums.length - 1; i>=0; i--) {
            while(!st.isEmpty() && st.peek() <= nums[i]) {
                st.pop();
            }
            ans[i] = st.isEmpty() ? -1: st.peek();
            st.push(nums[i]);
        }
        return ans;
    }
}
