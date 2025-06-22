// https://leetcode.com/problems/critical-connections-in-a-network/

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CriticalConnections {

    void dfs(int curr, int parent, List<List<Integer>> adj, int[] time, int[] lowTime, boolean[] visited, int t, List<List<Integer>> bridges) {
        visited[curr] = true;
        time[curr] = lowTime[curr] = t;
        t++;
        for(int neighbor: adj.get(curr)) {
            if(neighbor != parent) {
                if(!visited[neighbor]) {
                    dfs(neighbor, curr, adj, time, lowTime, visited, t, bridges);
                    lowTime[curr] = Math.min(lowTime[curr], lowTime[neighbor]);

                    if(time[curr] < lowTime[neighbor]) {
                        bridges.add(Arrays.asList(curr, neighbor));
                    }
                } else {
                    lowTime[curr] = Math.min(lowTime[curr], lowTime[neighbor]);
                }
            } 
        }
    }
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<n; i++) {
            adj.add(new ArrayList<>());
        }

        for(int i=0; i<connections.size(); i++) {
            int u = connections.get(i).get(0);
            int v = connections.get(i).get(1);
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        int[] time = new int[n];
        int[] lowTime = new int[n];

        boolean[] visited = new boolean[n];
        List<List<Integer>> bridges = new ArrayList<>();
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(i, -1, adj, time, lowTime, visited, 0, bridges);
            }
        }
        return bridges;
    }
}