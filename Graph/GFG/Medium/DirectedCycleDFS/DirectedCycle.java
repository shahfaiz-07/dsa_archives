
import java.util.ArrayList;

// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
public class DirectedCycle {
    private boolean dfsCycle(int curr, ArrayList<ArrayList<Integer>> adj, boolean[] visited, boolean[] inPath) {
        if (inPath[curr]) {
            return true;
        }
        if (visited[curr]) {
            return false;
        }
        inPath[curr] = true;
        visited[curr] = true;
        for (int neighbor : adj.get(curr)) {
            if (dfsCycle(neighbor, adj, visited, inPath)) {
                return true;
            }
        }
        inPath[curr] = false;
        return false;
    }

    // Function to detect cycle in a directed graph.
    public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {
        // code here
        boolean visited[] = new boolean[V];
        boolean inPath[] = new boolean[V];
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dfsCycle(i, adj, visited, inPath)) {
                return true;
            }
        }
        return false;
    }
}
