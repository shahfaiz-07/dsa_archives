// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

import java.util.ArrayList;
import java.util.List;

public class MColoring {
    boolean possible(int node, List<List<Integer>> adj, int c, int[] color) {
        for(int neighbor: adj.get(node)) {
            if(color[neighbor] == c) return false;
        }
        return true;
    }
    boolean canColor(int m, int node, List<List<Integer>> adj, int[] color) {
        if(node == adj.size()) {
            return true;
        }
        for(int i=1; i<=m; i++) {
            if(possible(node, adj, i, color)) {
                color[node] = i;
                if(canColor(m, node+1, adj, color)) {
                    return true;
                }
                color[node] = 0;
            }
        }
        return false;
    }
    boolean graphColoring(int v, List<int[]> edges, int m) {
        // code here
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<v; i++) {
            adj.add(new ArrayList<>());
        }
        
        for(int[] edge: edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        int color[] = new int[v];
        return canColor(m, 0, adj, color);
    }
}
