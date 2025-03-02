// https://neetcode.io/problems/islands-and-treasure
// https://leetcode.com/problems/walls-and-gates/description/

import java.util.ArrayDeque;
import java.util.Deque;

public class IslandsAndTreasures {
    class Pair {
        int first, second;
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    public void islandsAndTreasure(int[][] grid) {
        Deque<Pair> que = new ArrayDeque<>();
        for(int i=0; i<grid.length; i++) {
            for(int j=0; j<grid[0].length; j++) {
                if(grid[i][j] == 0) {
                    que.offer(new Pair(i, j));
                }
            }
        }

        int[][] dels = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int level = 1;
        while(!que.isEmpty()) {
            int size = que.size();
            for(int i=0; i<size; i++) {
                Pair curr = que.poll();
                for(int[] del: dels) {
                    int x = del[0] + curr.first, y = del[1] + curr.second;
                    if(x >= 0 && y >= 0 && x < grid.length && y < grid[0].length && grid[x][y] == Integer.MAX_VALUE) {
                        grid[x][y] = level;
                        que.offer(new Pair(x, y));
                    }
                }
            }
            level++;
        }
    }
}
