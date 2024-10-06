// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

import java.util.ArrayList;
import java.util.Arrays;

public class BellmanFord {
    static int[] bellman_ford(int V, ArrayList<ArrayList<Integer>> edges, int S) {
        // Write your code here
        final int MAGIC_NUM = (int)1e8;
        
        int dist[] = new int[V];
        Arrays.fill(dist, (int)MAGIC_NUM);
        dist[S] = 0;
        
        for(int i=1; i<=V-1; i++) {
            boolean changes = false;
            for(ArrayList<Integer> edge: edges) {
                int u = edge.get(0), v = edge.get(1), wt = edge.get(2);
                if(dist[u] != MAGIC_NUM && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    changes = true;
                }
            }
            if(!changes) return dist;
        }
        boolean changes = false;
        for(ArrayList<Integer> edge: edges) {
            int u = edge.get(0), v = edge.get(1), wt = edge.get(2);
            if(dist[u] != MAGIC_NUM && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                changes = true;
            }
        }
        if(!changes) return dist;
        return new int[]{-1};
    }
}
