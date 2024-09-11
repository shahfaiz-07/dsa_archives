// https://leetcode.com/problems/unique-paths-ii/
#include<bits/stdc++.h>
using namespace std;
// TABULATION - SPACE = O(N) + O(N)
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
        return 0;
    vector<int> dp(n);
    dp[0] = 1;
    vector<int> temp(n);
    for (int i = 0; i < m; i++)
    {
        temp[0] = (dp[0] == 1 && obstacleGrid[i][0] == 0) ? 1 : 0;
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                temp[j] = 0;
                continue;
            }
            if (!i && !j)
                continue;
            int u = (i > 0) ? dp[j] : 0;
            int l = (j > 0) ? temp[j - 1] : 0;
            temp[j] = u + l;
        }
        dp = temp;
    }
    return dp[n - 1];
}
// TABULATION - SPACE = O(M*N)
int uniquePathsWithObstaclesX(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
        return 0;
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((!i && !j) || obstacleGrid[i][j] == 1)
                continue;
            int u = (i > 0) ? dp[i - 1][j] : 0;
            int l = (j > 0) ? dp[i][j - 1] : 0;
            dp[i][j] = u + l;
        }
    }
    return dp[m - 1][n - 1];
}
// MEMOIZATION
int getPaths(vector<vector<int>> &og, int i, int j, vector<vector<int>> &dp)
{
    if (!i && !j)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (og[i][j] == 1)
        return dp[i][j] = 0;
    int u = getPaths(og, i - 1, j, dp);
    int l = getPaths(og, i, j - 1, dp);
    return dp[i][j] = u + l;
}

int uniquePathsWithObstacles1(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
        return 0;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return getPaths(obstacleGrid, m - 1, n - 1, dp);
}
int main(void) {
    
    return 0;
}