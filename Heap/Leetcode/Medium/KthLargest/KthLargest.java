// https://leetcode.com/problems/kth-largest-element-in-an-array/

import java.util.PriorityQueue;

public class KthLargest {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> b-a);

        for(int ele: nums) {
            pq.offer(ele);
        }

        for(int i=1; i<= k-1; i++) {
            pq.poll();
        }
        return pq.poll();
    }
}
