// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
import java.util.ArrayList;
public class AdjacencyListDFS {
    public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        ArrayList<Integer> dfs = new ArrayList<>();
        int visited[] = new int[V];
        DFS(0, adj, visited, dfs);
        return dfs;
    }

    void DFS(int start, ArrayList<ArrayList<Integer>> adj, int visited[], ArrayList<Integer> dfs) {
        visited[start] = 1;
        dfs.add(start);
        for (int ele : adj.get(start)) {
            if (visited[ele] == 0) {
                DFS(ele, adj, visited, dfs);
            }
        }
    }
}
