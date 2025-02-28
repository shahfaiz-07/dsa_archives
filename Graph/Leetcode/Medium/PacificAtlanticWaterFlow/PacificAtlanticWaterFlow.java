// https://leetcode.com/problems/pacific-atlantic-water-flow/
import java.util.*;
public class PacificAtlanticWaterFlow{
    void dfsPacific(int[][] heights, int[][] visited, int i, int j, int prevHeight) {
        if(i < 0 || j < 0 || i >= heights.length || j >= heights[0].length || visited[i][j] == 1 || heights[i][j] < prevHeight) {
            return;
        }
        visited[i][j] = 1;
        dfsPacific(heights, visited, i+1, j, heights[i][j]);
        dfsPacific(heights, visited, i-1, j, heights[i][j]);
        dfsPacific(heights, visited, i, j+1, heights[i][j]);
        dfsPacific(heights, visited, i, j-1, heights[i][j]);
    }
    void dfsAtlantic(int[][] heights, int[][] visited, int i, int j, int prevHeight, List<List<Integer>> ans) {
        if(i < 0 || j < 0 || i >= heights.length || j >= heights[0].length || visited[i][j] == 2 || heights[i][j] < prevHeight) {
            return;
        }
        if(visited[i][j] == 1) {
            List<Integer> temp = new ArrayList<>();
            temp.add(i);
            temp.add(j);
            ans.add(new ArrayList<>(temp));
        }
        visited[i][j] = 2;
        dfsAtlantic(heights, visited, i+1, j, heights[i][j], ans);
        dfsAtlantic(heights, visited, i-1, j, heights[i][j], ans);
        dfsAtlantic(heights, visited, i, j+1, heights[i][j], ans);
        dfsAtlantic(heights, visited, i, j-1, heights[i][j], ans);
    }
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        List<List<Integer>> ans = new ArrayList<>();
        int[][] visited = new int[heights.length][heights[0].length];
        // visited from pacific
        for(int i=0; i<heights.length; i++) {
            dfsPacific(heights, visited, i, 0, Integer.MIN_VALUE);
        }
        for(int j=0; j<heights[0].length; j++) {
            dfsPacific(heights, visited, 0, j, Integer.MIN_VALUE);
        }

        //visit from atlantic
        for(int i=0; i<heights.length; i++) {
            dfsAtlantic(heights, visited, i, heights[0].length - 1, Integer.MIN_VALUE, ans);
        }
        for(int j=0; j<heights[0].length; j++) {
            dfsAtlantic(heights, visited, heights.length - 1, j, Integer.MIN_VALUE, ans);
        }

        return ans;
    }
}