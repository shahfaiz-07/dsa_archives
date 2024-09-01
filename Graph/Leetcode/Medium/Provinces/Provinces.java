// https://leetcode.com/problems/number-of-provinces/
public class Provinces {
    void dfs(int[][] isConnected, int start, boolean[] visited) {
        visited[start] = true;
        for (int i = 0; i < isConnected.length; i++) {
            if (isConnected[start][i] == 1 && !visited[i]) {
                dfs(isConnected, i, visited);
            }
        }
    }

    public int findCircleNum(int[][] isConnected) {
        int count = 0;
        boolean visited[] = new boolean[isConnected.length];
        for (int i = 0; i < isConnected.length; i++) {
            if (!visited[i]) {
                count++;
                dfs(isConnected, i, visited);
            }
        }
        return count;
    }
}
