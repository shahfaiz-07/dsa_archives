// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
#include<bits/stdc++.h>
using namespace std;
// MEMOIZATION
int maximize(int N, int W, int index, int val[], int wt[], vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (W >= wt[0])
        {
            return (W / wt[0]) * val[0];
        }
        return 0;
    }
    if (dp[index][W] != -1)
        return dp[index][W];
    int pick = 0;
    if (W - wt[index] >= 0)
        pick = maximize(N, W - wt[index], index, val, wt, dp) + val[index];
    int notPick = maximize(N, W, index - 1, val, wt, dp);

    return dp[index][W] = max(pick, notPick);
}
int knapSack(int N, int W, int val[], int wt[])
{
    // code here
    vector<vector<int>> dp(N, vector<int>(W + 1, -1));
    return maximize(N, W, N - 1, val, wt, dp);
}

// TABULATION
int knapSack(int N, int W, int val[], int wt[])
{
    // code here
    vector<vector<int>> dp(N, vector<int>(W + 1, 0));
    for (int i = 0; i <= W; i++)
    {
        if (i >= wt[0])
        {
            dp[0][i] = (i / wt[0]) * val[0];
        }
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            int pick = 0;
            if (j - wt[i] >= 0)
                pick = dp[i][j - wt[i]] + val[i];
            int notPick = dp[i - 1][j];

            dp[i][j] = max(pick, notPick);
        }
    }
    return dp[N - 1][W];
}
int main(void) {
    
    return 0;
}