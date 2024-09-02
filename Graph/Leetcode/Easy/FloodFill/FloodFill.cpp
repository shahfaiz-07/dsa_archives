// https://leetcode.com/problems/flood-fill/description/
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &image, int sr, int sc, int color, int initialColor, vector<vector<int>> &ans)
{
    if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != initialColor || ans[sr][sc] == color)
    {
        return;
    }
    ans[sr][sc] = color;
    dfs(image, sr - 1, sc, color, initialColor, ans);
    dfs(image, sr + 1, sc, color, initialColor, ans);
    dfs(image, sr, sc - 1, color, initialColor, ans);
    dfs(image, sr, sc + 1, color, initialColor, ans);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    vector<vector<int>> ans(image); // better not to change the original data matrix
    dfs(image, sr, sc, color, image[sr][sc], ans);
    return ans;
}
int main(void)
{

    return 0;
}