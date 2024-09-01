// https://leetcode.com/problems/flood-fill/description/
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &image, int sr, int sc, int color, int initialColor, vector<vector<bool>> &visited)
{
    if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != initialColor || visited[sr][sc])
    {
        return;
    }
    visited[sr][sc] = true;
    image[sr][sc] = color;
    dfs(image, sr - 1, sc, color, initialColor, visited);
    dfs(image, sr + 1, sc, color, initialColor, visited);
    dfs(image, sr, sc - 1, color, initialColor, visited);
    dfs(image, sr, sc + 1, color, initialColor, visited);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
    dfs(image, sr, sc, color, image[sr][sc], visited);
    return image;
}
int main(void)
{

    return 0;
}