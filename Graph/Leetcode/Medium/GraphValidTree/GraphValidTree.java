// https://neetcode.io/problems/valid-tree
// https://leetcode.com/problems/graph-valid-tree/description/

import java.util.ArrayList;
import java.util.List;

public class GraphValidTree {
    boolean dfs(List<List<Integer>> adj, boolean[] visited, int curr, int prev) {
        if(visited[curr]) {
            return true;
        }

        visited[curr] = true;

        for(int neighbor: adj.get(curr)) {
            if(neighbor != prev && dfs(adj, visited, neighbor, curr))
                return true;
        }

        return false;
    }
    public boolean validTree(int n, int[][] edges) {
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<n; i++) {
            adj.add(new ArrayList<>());
        }

        for(int[] edge: edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

        boolean[] visited = new boolean[n];

        if(dfs(adj, visited, 0, -1)) return false;

        for(int i=1; i<n; i++) {
            if(!visited[i]) return false;
        }

        return true;
    }
}
