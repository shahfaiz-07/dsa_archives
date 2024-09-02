// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
import java.util.ArrayList;

public class DeteCycleDFS {
    boolean dfs(ArrayList<ArrayList<Integer>> adj, boolean visited[], int curr, int prev) {
        if(visited[curr]) {
            return true;
        }
        visited[curr] = true;
        for(int neighbor: adj.get(curr)) {
            if(prev != neighbor && dfs(adj, visited, neighbor, curr)) {
                return true;
            }
        }
        return false;
    }
    public boolean isCycle(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        boolean visited[] = new boolean[V];
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                if(dfs(adj, visited, i, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
}
