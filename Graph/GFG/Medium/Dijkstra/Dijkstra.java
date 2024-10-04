//https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Objects;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.TreeSet;
class Pair {

    int distance, node;

    Pair(int distance, int node) {
        this.distance = distance;
        this.node = node;
    }

    // FOR TREESET
    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        Pair pair = (Pair) obj;
        return pair.distance == distance && pair.node == node;
    }

    @Override
    public int hashCode() {
        return Objects.hash(distance, node);
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
    // USING TREESET
    static int[] dijkstra2(int V, ArrayList<ArrayList<ArrayList<Integer>>> adj, int S)
    {
        // Write your code here
        TreeSet<Pair> st = new TreeSet<>((x, y) -> {
            if(x.distance == y.distance) {
                return x.node - y.node;
            }
            return x.distance - y.distance;
        });
        
        st.add(new Pair(0, S));
        
        int[] minDist = new int[V];
        Arrays.fill(minDist, Integer.MAX_VALUE);
        
        minDist[S] = 0;
        
        while(!st.isEmpty()) {
            Pair curr = st.first();
            int node = curr.node, dist = curr.distance;
            st.remove(curr);
            for(ArrayList<Integer> neighbor: adj.get(node)) {
                int newDist = neighbor.get(1) + dist;
                
                if(minDist[neighbor.get(0)] > newDist) {
                    if(minDist[neighbor.get(0)] != Integer.MAX_VALUE) {
                        st.remove(new Pair(minDist[neighbor.get(0)], neighbor.get(0)));
                    }
                    minDist[neighbor.get(0)] = newDist;
                    st.add(new Pair(newDist, neighbor.get(0)));
                }
            }
        }
        return minDist;
    }
}
