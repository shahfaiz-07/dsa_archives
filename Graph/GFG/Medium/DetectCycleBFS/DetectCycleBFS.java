// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
class Pair {

    int first, second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
public class DetectCycleBFS {
    boolean bfs(ArrayList<ArrayList<Integer>> adj, boolean visited[], int start) {
        Deque<Pair> q = new ArrayDeque<>();
        q.offer(new Pair(start, start));
        visited[start] = true;
        while(!q.isEmpty()) {
            int curr = q.peek().first, prev = q.poll().second;
            for(int neighbor: adj.get(curr)) {
                if(visited[neighbor] && neighbor != prev) {
                    return true;
                } else if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.offer(new Pair(neighbor, curr));
                }
            }
        }
        return false;
    }
    public boolean isCycle(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        boolean visited[] = new boolean[V];
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                if(bfs(adj, visited, i)) {
                    return true;
                }
            }
        }
        return false;
    }
}
