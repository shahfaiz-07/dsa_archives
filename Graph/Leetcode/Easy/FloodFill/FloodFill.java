// https://leetcode.com/problems/flood-fill/description/
public class FloodFill {
    void dfs(int[][] image, int sr, int sc, int color, int initialColor, boolean[][] visited) {
        if (sr < 0 || sc < 0 || sr >= image.length || sc >= image[0].length || image[sr][sc] != initialColor || visited[sr][sc]) {
            return;
        }
        visited[sr][sc] = true;
        image[sr][sc] = color;
        dfs(image, sr, sc - 1, color, initialColor, visited);
        dfs(image, sr, sc + 1, color, initialColor, visited);
        dfs(image, sr - 1, sc, color, initialColor, visited);
        dfs(image, sr + 1, sc, color, initialColor, visited);
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        boolean[][] visited = new boolean[image.length][image[0].length];
        dfs(image, sr, sc, color, image[sr][sc], visited);
        return image;
    }
}
