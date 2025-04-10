// https://leetcode.com/problems/sliding-window-maximum/

import java.util.ArrayDeque;
import java.util.Deque;

public class SlidingWindowMaximum {

    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq = new ArrayDeque<>();
        int l=0, r=0;
        int[] ans = new int[nums.length - k + 1];
        while(r < nums.length) {
            while(!dq.isEmpty() && nums[dq.getLast()] <= nums[r]) {
                dq.removeLast();
            }
            dq.offerLast(r);
            if(dq.getFirst() < l) {
                dq.removeFirst();
            }
            if(r - l + 1 == k) {
                ans[l] = nums[dq.getFirst()];
                l++;
            }
            r++;
        }
        return ans;
    }
}