// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

import java.util.PriorityQueue;

public class KthSmallest {
    public static int kthSmallest(int[] arr, int k) {
        // Your code here
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> b-a);
        
        for(int i=0; i<k; i++) {
            pq.offer(arr[i]);
        }
        
        for(int i=k; i<arr.length; i++) {
            if(pq.peek() > arr[i]) {
                pq.poll();
                pq.offer(arr[i]);
            }
        }
        
        return pq.peek();
    }
}
