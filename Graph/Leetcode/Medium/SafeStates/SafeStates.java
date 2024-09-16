
import java.util.ArrayList;
import java.util.List;

// https://leetcode.com/problems/find-eventual-safe-states/
public class SafeStates {
    boolean dfsSafe(int[][] graph, int curr, boolean[] visited, int[] isSafe) {
        if (isSafe[curr] != 0) {
            return isSafe[curr] == 1 ? true : false;
        }
        if (visited[curr]) {
            return false;
        }
        if (graph[curr].length == 0) {
            isSafe[curr] = 1;
            return true;
        }
        visited[curr] = true;
        for (int neighbor : graph[curr]) {
            if (!dfsSafe(graph, neighbor, visited, isSafe)) {
                isSafe[curr] = -1;
                return false;
            }
        }
        visited[curr] = false;
        isSafe[curr] = 1;
        return true;
    }

    public List<Integer> eventualSafeNodes(int[][] graph) {
        List<Integer> ans = new ArrayList<>();
        boolean[] visited = new boolean[graph.length];
        int[] isSafe = new int[graph.length];
        // 0 is unknown, 1 is safe, -1 is unsafe
        for (int i = 0; i < graph.length; i++) {
            if (!visited[i] && isSafe[i] == 0) {
                dfsSafe(graph, i, visited, isSafe);
            }
        }
        for (int i = 0; i < graph.length; i++) {
            if (isSafe[i] == 1) {
                ans.add(i);
            }
        }
        return ans;
    }
}
