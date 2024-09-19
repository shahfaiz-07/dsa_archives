
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.List;

// https://leetcode.com/problems/find-eventual-safe-states/
public class SafeStates {
    // DFS
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

    //BFS
    public List<Integer> eventualSafeNodes2(int[][] graph) {
        List<List<Integer>> revGraph = new ArrayList<>();
        for (int i = 0; i < graph.length; i++) {
            revGraph.add(new ArrayList<>());
        }
        int[] inDegree = new int[graph.length];
        for (int i = 0; i < graph.length; i++) {
            inDegree[i] = graph[i].length;
            for (int neighbor : graph[i]) {
                revGraph.get(neighbor).add(i);
            }
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < revGraph.size(); i++) {
            if (inDegree[i] == 0) {
                q.offer(i);
            }
        }
        List<Integer> ans = new ArrayList<>();
        while (!q.isEmpty()) {
            int curr = q.poll();
            ans.add(curr);
            for (int neighbor : revGraph.get(curr)) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.offer(neighbor);
                }
            }
        }
        Collections.sort(ans);
        return ans;
    }
}
