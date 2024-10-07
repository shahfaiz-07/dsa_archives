// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

import java.util.PriorityQueue;

class Pair {

    int wt, node;

    Pair(int wt, int node) {
        this.wt = wt;
        this.node = node;
    }
}
public class Prims {
    static int spanningTree(int V, int E, List<List<int[]>> adj) {
        // Code Here.
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> {
            return a.wt - b.wt;
        });
        boolean visited[] = new boolean[V];

        pq.offer(new Pair(0, 0)); // wt, node, parent
        int sum = 0;
        while (!pq.isEmpty()) {
            Pair curr = pq.poll();
            int node = curr.node;
            if (visited[node]) {
                continue;
            }
            int wt = curr.wt;
            visited[node] = true;
            sum += wt;
            for (int[] neighbor : adj.get(node)) {
                int adjNode = neighbor[0], adjWt = neighbor[1];
                if (!visited[adjNode]) {
                    pq.offer(new Pair(adjWt, adjNode));
                }
            }
        }
        return sum;
    }
}
