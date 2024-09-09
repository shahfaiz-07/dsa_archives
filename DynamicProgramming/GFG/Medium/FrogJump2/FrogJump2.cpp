// https://www.geeksforgeeks.org/problems/minimal-cost/1
#include<bits/stdc++.h>
// TABULATION
int minimizeCost(vector<int> &arr, int &k)
{
    // Code here
    int n = arr.size() - 1;
    if (n == 0)
        return 0;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);
    for (int i = 2; i <= n; i++)
    {
        int min = INT_MAX;
        for (int j = 1; j <= k && i - j >= 0; j++)
        {
            int jump = dp[i - j] + abs(arr[i] - arr[i - j]);
            if (jump < min)
                min = jump;
        }
        dp[i] = min;
    }
    return dp[n];
}
// MEMOIZATION
int jump(vector<int> &arr, int k, int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int mini = INT_MAX;
    for (int i = 1; i <= k && n - i >= 0; i++)
    {
        int j = jump(arr, k, n - i, dp) + abs(arr[n] - arr[n - i]);
        if (j < mini)
        {
            mini = j;
        }
    }
    return dp[n] = mini;
}

int minimizeCost2(vector<int> &arr, int &k)
{
    // Code here
    vector<int> dp(arr.size(), -1);
    return jump(arr, k, arr.size() - 1, dp);
}
using namespace std;
int main(void) {
    
    return 0;
}