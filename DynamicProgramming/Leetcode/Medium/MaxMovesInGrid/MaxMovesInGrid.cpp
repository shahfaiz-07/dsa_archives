// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/
#include<bits/stdc++.h>
using namespace std;
int move(vector<vector<int>> &grid, int i, int j, int prev, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || prev >= grid[i][j])
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int m1 = move(grid, i, j + 1, grid[i][j], dp);
    int m2 = move(grid, i + 1, j + 1, grid[i][j], dp);
    int m3 = move(grid, i - 1, j + 1, grid[i][j], dp);

    return dp[i][j] = max(m1, max(m2, m3)) + 1;
}

int maxMoves(vector<vector<int>> &grid)
{
    int maxi = 0;
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    for (int i = 0; i < grid.size(); i++)
    {
        maxi = max(maxi, move(grid, i, 0, 0, dp));
    }
    return maxi - 1;
}
int main(void) {
    
    return 0;
}