// https://www.naukri.com/code360/problems/0-1-knapsack_920542
#include<bits/stdc++.h>
using namespace std;
// MEMOIZATION
int getMaxValue(vector<int> &weight, vector<int> &value, int maxWeight, int i, vector<vector<int>> &dp)
{
    if (maxWeight == 0 || i == -1)
    {
        return 0;
    }
    if (dp[maxWeight][i])
    {
        return dp[maxWeight][i];
    }
    // pick and not pick
    int pick = INT_MIN;
    if (maxWeight - weight[i] >= 0)
    {
        pick = getMaxValue(weight, value, maxWeight - weight[i], i - 1, dp) + value[i];
    }
    int notPick = getMaxValue(weight, value, maxWeight, i - 1, dp);
    return dp[maxWeight][i] = max(pick, notPick);
}
int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    // Write your code here
    vector<vector<int>> dp(maxWeight + 1, vector<int>(n, 0));
    return getMaxValue(weight, value, maxWeight, n - 1, dp);
}

// TABULATION
int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    // Write your code here
    vector<vector<int>> dp(maxWeight + 1, vector<int>(n, 0));
    for (int i = 1; i <= maxWeight; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            int pick = INT_MIN;
            if (i - weight[j] >= 0)
            {
                pick = dp[i - weight[j]][j - 1] + value[j];
            }
            int notPick = dp[i][j - 1];
            dp[i][j] = max(pick, notPick);
        }
    }
    return dp[maxWeight][n - 1];
}
int main(void) {
    
    return 0;
}