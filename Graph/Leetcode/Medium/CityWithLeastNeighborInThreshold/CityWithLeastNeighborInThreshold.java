// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

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
public class CityWithLeastNeighborInThreshold {
    // Using Floyd Warshall
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        // creating adj matrix
        int adj[][] = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(adj[i], (int) 1e4 + 1);
        }
        for (int[] edge : edges) {
            adj[edge[0]][edge[1]] = edge[2];
            adj[edge[1]][edge[0]] = edge[2];
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == via || j == via || i == j) {
                        continue;
                    }
                    long viaDist = adj[i][via] + adj[via][j];
                    if (viaDist < adj[i][j]) {
                        adj[i][j] = (int) viaDist;
                    }
                }
            }
        }

        int lastMinCities = Integer.MAX_VALUE, lastCityWithMin = -1;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (adj[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= lastMinCities) {
                lastMinCities = count;
                lastCityWithMin = i;
            }
        }
        return lastCityWithMin;
    }
    // Using Dijkstra
    int dijkstra(int n, List<List<Pair>> adj, int threshold, int src) {
        int minDist[] = new int[n];
        Arrays.fill(minDist, Integer.MAX_VALUE);
        minDist[src] = 0;
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> {
            return a.first - b.first;
        });
        pq.offer(new Pair(0, src));

        while(!pq.isEmpty()) {
            Pair curr = pq.poll();
            int node = curr.second, dist = curr.first;
            for(Pair neighbor: adj.get(node)) {
                int newDist = neighbor.second + dist;
                if(minDist[neighbor.first] > newDist) {
                    minDist[neighbor.first] = newDist;
                    pq.offer(new Pair(newDist, neighbor.first));
                }
            }
        }
        int count = 0;
        for(int dist: minDist) {
            if(dist <= threshold) count++;
        }
        return count;
    }
    public int findTheCity2(int n, int[][] edges, int distanceThreshold) {
        // creating adj matrix
        List<List<Pair>> adj = new ArrayList<>();
        for(int i=0; i<n; i++) {
            adj.add(new ArrayList<>());
        }
        for(int[] edge: edges) {
            adj.get(edge[0]).add(new Pair(edge[1], edge[2]));
            adj.get(edge[1]).add(new Pair(edge[0], edge[2]));
        }
        int lastMinCities = Integer.MAX_VALUE, lastCity = -1;
        for(int i=0; i<n; i++) {
            int count = dijkstra(n, adj, distanceThreshold, i);
            if(count <= lastMinCities) {
                lastMinCities = count;
                lastCity = i;
            }
        }
        return lastCity;
    }
}
