// https://www.geeksforgeeks.org/problems/chocolates-pickup/1
#include<bits/stdc++.h>
using namespace std;
// TABULATION
int solve(int n, int m, vector<vector<int>> &grid)
{
    // code here
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m)));
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
            {
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            }
            else
            {
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = INT_MIN;
                for (int k1 = -1; k1 <= 1; k1++)
                {
                    for (int k2 = -1; k2 <= 1; k2++)
                    {
                        if ((j1 == 0 && k1 == -1) ||
                            (j2 == 0 && k2 == -1) ||
                            (j1 == m - 1 && k1 == 1) ||
                            (j2 == m - 1 && k2 == 1))
                            continue;
                        maxi = max(maxi, dp[i + 1][j1 + k1][j2 + k2]);
                    }
                }
                maxi += grid[i][j1];
                if (j1 != j2)
                {
                    maxi += grid[i][j2];
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m - 1];
}
// MEMOIZATION
int traverse(int n, int m, vector<vector<int>> &grid, int i, int j1, int j2, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
    {
        return INT_MIN;
    }
    if (i == n - 1)
    {
        return (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }
    int maxi = INT_MIN;
    for (int k1 = -1; k1 <= 1; k1++)
    {
        for (int k2 = -1; k2 <= 1; k2++)
        {
            maxi = max(maxi, traverse(n, m, grid, i + 1, j1 + k1, j2 + k2, dp));
        }
    }
    maxi += grid[i][j1];
    if (j1 != j2)
    {
        maxi += grid[i][j2];
    }
    return dp[i][j1][j2] = maxi;
}

int solve(int n, int m, vector<vector<int>> &grid)
{
    // code here
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return traverse(n, m, grid, 0, 0, m - 1, dp);
}
int main(void) {
    
    return 0;
}