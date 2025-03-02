// https://leetcode.com/problems/min-cost-climbing-stairs/
#include<bits/stdc++.h>
using namespace std;
// MEMOIZATION
int minCostClimbingStairs(vector<int> &cost)
{
    vector<int> dp(cost.size());
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < cost.size(); i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
    return min(dp[cost.size() - 1], dp[cost.size() - 2]);
}
    
// TABULATION
int minCostClimbingStairs(vector<int> &cost)
{
    vector<int> dp(cost.size());
    int prev_1 = cost[1], prev_2 = cost[0], curr = cost[1];
    for (int i = 2; i < cost.size(); i++)
    {
        curr = cost[i] + min(prev_1, prev_2);
        prev_2 = prev_1;
        prev_1 = curr;
    }
    return min(curr, prev_2);
}

// SPACE-OPTIMIZED
int minCostClimbingStairs(int[] cost)
{
    int prev_1 = cost[1], prev_2 = cost[0], curr = cost[1];

    for (int i = 2; i < cost.length; i++)
    {
        curr = cost[i] + Math.min(prev_1, prev_2);
        prev_2 = prev_1;
        prev_1 = curr;
    }

    return Math.min(curr, prev_2);
}