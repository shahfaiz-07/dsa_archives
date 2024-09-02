// https://leetcode.com/problems/flood-fill/description/
public class FloodFill {
    void dfs(int[][] image, int sr, int sc, int color, int initialColor, int[][] ans) {
        if (sr < 0 || sc < 0 || sr >= image.length || sc >= image[0].length || image[sr][sc] != initialColor || ans[sr][sc] == color) {
            return;
        }
        ans[sr][sc] = color;
        dfs(image, sr, sc - 1, color, initialColor, ans);
        dfs(image, sr, sc + 1, color, initialColor, ans);
        dfs(image, sr - 1, sc, color, initialColor, ans);
        dfs(image, sr + 1, sc, color, initialColor, ans);
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int[][] ans = image.clone(); // better not to change the original array
        dfs(image, sr, sc, color, image[sr][sc], ans);
        return image;
    }
}
