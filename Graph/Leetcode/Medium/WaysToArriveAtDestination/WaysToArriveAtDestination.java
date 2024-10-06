// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
class Pair {

    long first, second;

    Pair(long first, long second) {
        this.first = first;
        this.second = second;
    }
}
public class WaysToArriveAtDestination {
    public int countPaths(int n, int[][] roads) {
        final int MOD = (int)1e9 + 7;

        List<List<Pair>> adj = new ArrayList<>();
        for(int i=0; i<n; i++) {
            adj.add(new ArrayList<>());
        }

        for(int edge[] : roads) {
            adj.get(edge[0]).add(new Pair(edge[1], edge[2]));
            adj.get(edge[1]).add(new Pair(edge[0], edge[2]));
        }

        long minCost[] = new long[n];
        Arrays.fill(minCost, Long.MAX_VALUE);
        minCost[0] = 0;
        long minWays[] = new long[n];
        minWays[0] = 1;

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> {
            return Long.compare(a.first,b.first);
        });

        pq.offer(new Pair(0, 0));

        while(!pq.isEmpty()) {
            Pair curr = pq.poll();
            long cost = curr.first, node = curr.second;
            long ways = minWays[(int)node];
            for(Pair neighbor: adj.get((int)node)) {
                long newCost = cost + neighbor.second;
                int adjNode = (int)neighbor.first;
                if(minCost[adjNode] > newCost) {
                    minCost[adjNode] = newCost;
                    minWays[adjNode] = ways;
                    pq.offer(new Pair(newCost, adjNode));
                } else if(minCost[adjNode] == newCost) {
                    minWays[adjNode] = (minWays[adjNode] + ways)%MOD;
                }
            }
        }

        return (int)(minWays[n - 1]%MOD);
    }
}