// https://leetcode.com/problems/network-delay-time/

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

class Pair {

    int first, second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
public class NetworkDelayTime {
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<Pair>> adj = new ArrayList<>();

        for(int i=0; i<=n; i++) {
            adj.add(new ArrayList<>());
        }

        for(int[] edge: times) {
            adj.get(edge[0]).add(new Pair(edge[1], edge[2]));
        }

        int minTime[] = new int[n + 1];
        Arrays.fill(minTime, Integer.MAX_VALUE);
        minTime[k] = 0;

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> {
            return a.first - b.second;
        });

        pq.offer(new Pair(0, k));

        while(!pq.isEmpty()) {
            Pair curr = pq.poll();

            int time = curr.first, node = curr.second;

            for(Pair neighbor: adj.get(node)) {
                int newTime = neighbor.second + time;

                if(minTime[neighbor.first] > newTime) {
                    minTime[neighbor.first] = newTime;
                    pq.offer(new Pair(newTime, neighbor.first));
                }
            }
        }

        int max = Integer.MIN_VALUE;

        // skip 0th index
        for(int i=1; i<=n; i++) {
            if(max < minTime[i]) {
                max = minTime[i];
            }
        }
        return max == Integer.MAX_VALUE ? -1 : max;
    }
}
