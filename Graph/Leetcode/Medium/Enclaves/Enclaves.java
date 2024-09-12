// https://leetcode.com/problems/number-of-enclaves/
import java.util.ArrayDeque;
import java.util.Deque;

class Pair {
    int first, second;
    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
public class Enclaves {
    public int numEnclaves(int[][] grid) {
        if(grid.length <= 2 || grid[0].length <= 2) {
            return 0;
        }
        Deque<Pair> q = new ArrayDeque<>();
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        for(int i=0; i<grid.length; i++) {
            if(grid[i][0] == 1) {
                q.offer(new Pair(i, 0));
                visited[i][0] = true;
            }
            if(grid[i][grid[0].length - 1] == 1) {
                q.offer(new Pair(i, grid[0].length - 1));
                visited[i][grid[0].length - 1] = true;
            }
        }
        for(int i=1; i<grid[0].length - 1; i++) {
            if(grid[0][i] == 1) {
                q.offer(new Pair(0, i));
                visited[0][i] = true;
            }
            if(grid[grid.length - 1][i] == 1) {
                q.offer(new Pair(grid.length - 1, i));
                visited[grid.length - 1][i] = true;
            }
        }
        // multi source BFS
        int dels[][] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(!q.isEmpty()) {
            int currX = q.peek().first, currY = q.peek().second;
            q.poll();
            for(int[] del: dels) {
                int i = currX + del[0], j = currY + del[1];
                if(i >= 0 && i < grid.length && j >= 0 && j < grid[0].length && grid[i][j] != 0 && !visited[i][j])  {
                    visited[i][j] = true;
                    q.offer(new Pair(i, j));
                }
            }
        }
        int count = 0;
        for(int i=0; i<grid.length; i++) {
            for(int j=0; j<grid[0].length; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
}