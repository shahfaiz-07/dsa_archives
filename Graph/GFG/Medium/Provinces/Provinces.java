// https://www.geeksforgeeks.org/problems/number-of-provinces/1
import java.util.ArrayList;

public class Provinces {

    static void dfs(ArrayList<ArrayList<Integer>> adj, boolean[] visited, int start) {
        if (!visited[start]) {
            visited[start] = true;
            for (int i = 0; i < adj.size(); i++) {
                if (adj.get(start).get(i) == 1 && !visited[i]) {
                    dfs(adj, visited, i);
                }
            }
        }
    }

    static int numProvinces(ArrayList<ArrayList<Integer>> adj, int V) {
        // code here
        boolean visited[] = new boolean[V];
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                dfs(adj, visited, i);
            }
        }
        return count;
    }

    public static void main(String[] args) {

    }
}
