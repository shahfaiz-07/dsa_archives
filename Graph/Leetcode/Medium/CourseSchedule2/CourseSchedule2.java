// https://leetcode.com/problems/course-schedule-ii/
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;


public class CourseSchedule2 {
    // DFS
    boolean dfsTopo(List<List<Integer>> adj, int curr, boolean[] visited, boolean[] inPath, Deque<Integer> stack) {
        if (inPath[curr]) {
            return true;
        }
        if (visited[curr]) {
            return false;
        }
        visited[curr] = true;
        inPath[curr] = true;
        for (int neighbor : adj.get(curr)) {
            if (dfsTopo(adj, neighbor, visited, inPath, stack)) {
                return true;
            }
        }
        stack.push(curr);
        inPath[curr] = false;
        return false;
    }
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < prerequisites.length; i++) {
            adj.get(prerequisites[i][1]).add(prerequisites[i][0]);
        }
        Deque<Integer> stack = new ArrayDeque<>();
        boolean visited[] = new boolean[numCourses];
        boolean inPath[] = new boolean[numCourses];
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && dfsTopo(adj, i, visited, inPath, stack)) {
                return new int[]{};
            }
        }
        int ans[] = new int[numCourses];
        for (int i = 0; i < numCourses; i++) {
            ans[i] = stack.pop();
        }
        return ans;
    }
    // BFS
    public int[] findOrder2(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }
        int inDegree[] = new int[numCourses];
        for (int i = 0; i < prerequisites.length; i++) {
            adj.get(prerequisites[i][1]).add(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.offer(i);
            }
        }
        int count = 0;
        int ans[] = new int[numCourses];
        while (!q.isEmpty()) {
            int curr = q.poll();
            ans[count++] = curr;
            for (int neighbor : adj.get(curr)) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.offer(neighbor);
                }
            }
        }
        if (count != numCourses) {
            return new int[]{};
        }
        return ans;
    }
}
