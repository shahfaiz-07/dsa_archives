// https://www.geeksforgeeks.org/problems/geeks-training/1
#include<bits/stdc++.h>
using namespace std;
// TABULATION - Space = O(4) + O(4) --> temp
int maximumPoints(vector<vector<int>> &arr, int n)
{
    // Code here
    vector<int> dp(4);
    dp[0] = max(arr[0][1], arr[0][2]);
    dp[1] = max(arr[0][0], arr[0][2]);
    dp[2] = max(arr[0][1], arr[0][0]);
    dp[3] = max({arr[0][1], arr[0][0], arr[0][2]});
    for (int k = 1; k < n; k++)
    {
        vector<int> temp(4);
        for (int prevInd = 0; prevInd <= 3; prevInd++)
        {
            for (int i = 0; i <= 2; i++)
            {
                if (prevInd != i)
                {
                    int j = dp[i] + arr[k][i];
                    temp[prevInd] = max(temp[prevInd], j);
                }
            }
        }
        dp = temp;
    }
    return dp[3];
}
// TABULATION - Space = O(N*4)
int maximumPointsX(vector<vector<int>> &arr, int n)
{
    // Code here
    vector<vector<int>> dp(n, vector<int>(4));
    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]);
    dp[0][2] = max(arr[0][1], arr[0][0]);
    dp[0][3] = max({arr[0][1], arr[0][0], arr[0][2]});
    for (int k = 1; k < n; k++)
    {
        for (int prevInd = 0; prevInd <= 3; prevInd++)
        {
            for (int i = 0; i <= 2; i++)
            {
                if (prevInd != i)
                {
                    int j = dp[k - 1][i] + arr[k][i];
                    dp[k][prevInd] = max(dp[k][prevInd], j);
                }
            }
        }
    }
    return dp[n - 1][3];
}
// MEMOIZATION
int maxOf(vector<vector<int>> &arr, int n, int prevInd, vector<vector<int>> &dp)
{
    if (n < 0)
    {
        return 0;
    }
    if (dp[n][prevInd])
    {
        return dp[n][prevInd];
    }
    int max = INT_MIN;
    for (int i = 0; i <= 2; i++)
    {
        if (prevInd != i)
        {
            int j = maxOf(arr, n - 1, i, dp) + arr[n][i];
            if (j > max)
            {
                max = j;
            }
        }
    }
    return dp[n][prevInd] = max;
}
int maximumPoints2(vector<vector<int>> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(4));
    return maxOf(arr, n - 1, 3, dp);
}
int main(void) {
    
    return 0;
}