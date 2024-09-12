
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
public class DistinctIslands {
    void dfs(int[][] grid, int x, int y, int startX, int startY, boolean[][] visited, List<String> path, int[][] dels) {
        visited[x][y] = true;
        path.add((x - startX) + "," + (y - startY));
        for (int[] del : dels) {
            int i = x + del[0], j = y + del[1];
            if (i >= 0 && j >= 0 && i < grid.length && j < grid[0].length && grid[i][j] == 1 && !visited[i][j]) {
                dfs(grid, i, j, startX, startY, visited, path, dels);
            }
        }
    }

    int countDistinctIslands(int[][] grid) {
        // Your Code here
        boolean visited[][] = new boolean[grid.length][grid[0].length];
        Set<List<String>> set = new HashSet<>();
        int dels[][] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    List<String> path = new ArrayList<>();
                    dfs(grid, i, j, i, j, visited, path, dels);
                    set.add(path);
                }
            }
        }
        return set.size();
    }
}
