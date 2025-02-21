// https://leetcode.com/problems/top-k-frequent-elements/
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class TopKFrequentElements {
    class Pair {
        int first, second;
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();

        PriorityQueue<Pair> minHeap = new PriorityQueue<>((a, b) -> {
            return a.first-b.first;
        });

        for(int ele: nums) {
            mp.compute(ele, (key, value) -> value == null ? 1 : value + 1); // map[ele] = freq
        }

        for(Map.Entry<Integer, Integer> e: mp.entrySet()) {
            int freq = e.getValue();
            int ele = e.getKey();

            if(minHeap.size() < k) {
                minHeap.offer(new Pair(freq, ele));
            } else {
                if(minHeap.peek().first < freq) {
                    minHeap.poll();
                    minHeap.offer(new Pair(freq, ele));
                }
            }
        }

        int[] arr = new int[k];
        int index = 0;
        while(!minHeap.isEmpty()) {
            arr[index++] = minHeap.poll().second;
        }
        return arr;
    }
}