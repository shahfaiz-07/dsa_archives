
import java.util.ArrayDeque;
import java.util.Deque;

// https://leetcode.com/problems/is-graph-bipartite/
public class Bipartite {
    // DFS
    private boolean colorGraph(int[][] graph, int curr, int prevColor, int[] visited) {
        if (visited[curr] != 0) {
            return visited[curr] == -prevColor;
        }
        visited[curr] = -prevColor;
        for (int neighbor : graph[curr]) {
            if (!colorGraph(graph, neighbor, -prevColor, visited)) {
                return false;
            }
        }
        return true;
    }
    // BFS
    private boolean colorGraph2(int[][] graph, int start, int[] visited) {
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(start);
        System.out.println("Coloring " + start + " :" + (1));
        visited[start] = 1;
        while (!q.isEmpty()) {
            int curr = q.poll();
            for (int neighbor : graph[curr]) {
                if (visited[neighbor] == 0) {
                    System.out.println("Coloring " + neighbor + " :" + (-visited[curr]));
                    visited[neighbor] = -visited[curr];
                    q.offer(neighbor);
                } else if (visited[neighbor] == visited[curr]) {
                    return false;
                }
            }
        }
        return true;
    }
    public boolean isBipartite(int[][] graph) {
        int visited[] = new int[graph.length];
        for (int i = 0; i < graph.length; i++) {
            if (visited[i] == 0 && !colorGraph(graph, i, 1, visited)) {
                return false;
            }
        }
        return true;
    }
}
