// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
#include <bits/stdc++.h>
using namespace std;

// MEMOIZED
int maximize(int ind, int canBuy, vector<int> &prices, vector<vector<int>> &dp)
{
    if (ind == prices.size())
        return 0;
    if (dp[ind][canBuy] != -1)
        return dp[ind][canBuy];
    if (canBuy)
    {
        return dp[ind][canBuy] = max(maximize(ind + 1, 0, prices, dp) - prices[ind],
                                     maximize(ind + 1, 1, prices, dp));
    }
    return dp[ind][canBuy] = max(maximize(ind + 1, 1, prices, dp) + prices[ind],
                                 maximize(ind + 1, 0, prices, dp));
}
int maxProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    return maximize(0, 1, prices, dp);
}

// TABULATED
int maxProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));

    for (int ind = prices.size() - 1; ind >= 0; ind--)
    {
        dp[ind][0] = max(dp[ind + 1][1] + prices[ind], dp[ind + 1][0]);
        dp[ind][1] = max(dp[ind + 1][0] - prices[ind], dp[ind + 1][1]);
    }

    return dp[0][1];
}