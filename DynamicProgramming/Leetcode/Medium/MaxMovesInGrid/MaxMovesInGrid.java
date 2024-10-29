// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/

import java.util.Arrays;

public class MaxMovesInGrid {
    int move(int[][] grid, int i, int j, int prev, int[][] dp) {
        if(i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || prev >= grid[i][j]) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int m1 = move(grid, i, j+1, grid[i][j], dp);
        int m2 = move(grid, i+1, j+1, grid[i][j], dp);
        int m3 = move(grid, i-1, j+1, grid[i][j], dp);

        dp[i][j] = Math.max(m1, Math.max(m2, m3)) + 1;
        return dp[i][j];
    }
    public int maxMoves(int[][] grid) {
        int maxi = 0;
        int[][] dp = new int[grid.length][grid[0].length];
        for(int i=0; i<grid.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        for(int i=0; i<grid.length; i++) {
            maxi = Math.max(maxi, move(grid, i, 0, 0, dp));
        }
        return maxi-1;
    }
}
