// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class Kosaraju {

    void dfs(int curr, ArrayList<ArrayList<Integer>> adj, boolean[] visited, Deque<Integer> st) {
        visited[curr] = true;
        for(int neighbor: adj.get(curr)) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited, st);
            }
        }
        st.push(curr);
    }
    
    void dfs2(int curr, List<List<Integer>> adj, boolean[] visited) {
        visited[curr] = true;
        for(int neighbor: adj.get(curr)) {
            if(!visited[neighbor]) {
                dfs2(neighbor, adj, visited);
            }
        }
    }
    // Function to find number of strongly connected components in the graph.
    public int kosaraju(ArrayList<ArrayList<Integer>> adj) {
        // code here
        int V = adj.size();
        Deque<Integer> st = new ArrayDeque<>();
        boolean[] visited = new boolean[V];
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }
        
        List<List<Integer>> rAdj = new ArrayList<>();
        
        for(int i=0; i<V; i++) {
            rAdj.add(new ArrayList<>());
        }
        for(int i=0; i<V; i++) {
            for(int neighbor: adj.get(i)) {
                rAdj.get(neighbor).add(i);
            }
        }
        
        int c = 0;
        boolean[] rVisited = new boolean[V];
        while(!st.isEmpty()) {
            int curr = st.pop();
            if(!rVisited[curr]) {
                c++;
                dfs2(curr, rAdj, rVisited);
            }
        }
        return c;
    }
}