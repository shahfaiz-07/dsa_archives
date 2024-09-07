// https://leetcode.com/problems/all-paths-from-source-to-target/description/
import java.util.ArrayList;
import java.util.List;

public class DAGAllPaths {
    void traversePath(int[][] graph, int curr, boolean[] visited, List<List<Integer>> paths, List<Integer> path) {
        if (curr == graph.length - 1) {
            path.add(curr);
            paths.add(new ArrayList<>(path));
            return;
        }
        if (visited[curr]) {
            return;
        }
        visited[curr] = true;
        path.add(curr);
        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                traversePath(graph, neighbor, visited, paths, path);
                path.remove(path.size() - 1);
            }
        }
        visited[curr] = false;
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> paths = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        boolean visited[] = new boolean[graph.length];
        traversePath(graph, 0, visited, paths, path);
        return paths;
    }

    public static void main(String[] args) {
        
    }
}