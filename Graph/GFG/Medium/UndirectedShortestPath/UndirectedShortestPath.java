// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;

class Pair {

    int first, second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
public class UndirectedShortestPath {
    public int[] shortestPath(int[][] edges, int n, int m, int src) {
        // Code here
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            adj.get(edges[i][0]).add(edges[i][1]);
            adj.get(edges[i][1]).add(edges[i][0]);
        }
        int[] dist = new int[n];
        Arrays.fill(dist, -1);
        dist[src] = 0;
        Deque<Pair> q = new ArrayDeque<>();
        q.offer(new Pair(src, 0));
        while (!q.isEmpty()) {
            int curr = q.peek().first;
            int distance = q.peek().second;
            q.poll();
            for (int neighbor : adj.get(curr)) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = distance + 1;
                    q.offer(new Pair(neighbor, distance + 1));
                }
            }
        }
        return dist;
    }
}