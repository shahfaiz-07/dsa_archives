// https://leetcode.com/problems/unique-paths/
#include<bits/stdc++.h>
using namespace std;
// TABULATION - SPACE = O(N)
int uniquePaths(int m, int n)
{
    vector<int> dp(n);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n);
        temp[0] = 1;
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i] = 1;
            else
            {
                int u = (i > 0) ? dp[j] : 0;
                int l = (j > 0) ? temp[j - 1] : 0;
                temp[j] = u + l;
            }
        }
        dp = temp;
    }
    return dp[n - 1];
}
// TABULATION - SPACE = O(M*N)
int uniquePaths2(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int u = (i > 0) ? dp[i - 1][j] : 0;
                int l = (j > 0) ? dp[i][j - 1] : 0;
                dp[i][j] = u + l;
            }
        }
    }
    return dp[m - 1][n - 1];
}
// MEMOIZATION
int getPaths(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int u = getPaths(i - 1, j, dp);
    int l = getPaths(i, j - 1, dp);
    return dp[i][j] = l + u;
}

int uniquePaths1(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return getPaths(m - 1, n - 1, dp);
}
int main(void) {
    
    return 0;
}