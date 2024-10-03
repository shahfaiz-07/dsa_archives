//https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
class Pair {

    int distance, node;

    Pair(int distance, int node) {
        this.distance = distance;
        this.node = node;
    }
}
public class Dijkstra {
    // USING PRIORITY QUEUE
    static int[] dijkstra(int V, ArrayList<ArrayList<ArrayList<Integer>>> adj, int S) {
        // Write your code here
        Queue<Pair> pq = new PriorityQueue<>((x, y) -> {
            if (x.distance == y.distance) {
                return x.node - y.node;
            }
            return x.distance - y.distance;
        });

        pq.offer(new Pair(0, S));

        int[] minDist = new int[V];
        Arrays.fill(minDist, Integer.MAX_VALUE);

        minDist[S] = 0;

        while (!pq.isEmpty()) {
            Pair curr = pq.poll();

            int node = curr.node, distance = curr.distance;

            for (ArrayList<Integer> neighbor : adj.get(node)) {
                int newDist = distance + neighbor.get(1);

                if (minDist[neighbor.get(0)] > newDist) {
                    minDist[neighbor.get(0)] = newDist;
                    pq.offer(new Pair(newDist, neighbor.get(0)));
                }
            }
        }

        return minDist;
    }
}
