// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
#include <bits/stdc++.h>
using namespace std;

int recurse(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j])
        return dp[i][j];
    int mini = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int op = arr[i - 1] * arr[k] * arr[j] + recurse(arr, i, k, dp) + recurse(arr, k + 1, j, dp);
        mini = min(mini, op);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr)
{
    // code here
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
    return recurse(arr, 1, arr.size() - 1, dp);
}