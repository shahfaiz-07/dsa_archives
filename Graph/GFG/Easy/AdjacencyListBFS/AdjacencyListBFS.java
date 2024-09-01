// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;

public class AdjacencyListBFS {
    public ArrayList<Integer> bfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        ArrayList<Integer> bfs = new ArrayList<>();
        int visited[] = new int[V];
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        visited[0] = 1;
        bfs.add(0);
        while (!q.isEmpty()) {
            int curr = q.poll();
            for (int neighbor : adj.get(curr)) {
                if (visited[neighbor] == 0) {
                    q.offer(neighbor);
                    bfs.add(neighbor);
                    visited[neighbor] = 1;
                }
            }
        }
        return bfs;
    }
    public static void main(String[] args) {
        
    }
}
