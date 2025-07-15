// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION
int maximize(vector<int> &prices, int ind, int canBuy, int fee, vector<vector<int>> &dp)
{
    if (ind == prices.size())
        return 0;
    if (dp[ind][canBuy] != -1)
        return dp[ind][canBuy];

    if (canBuy)
    {
        return dp[ind][canBuy] = max(maximize(prices, ind + 1, 0, fee, dp) - prices[ind] - fee,
                                     maximize(prices, ind + 1, 1, fee, dp));
    }
    else
    {
        return dp[ind][canBuy] = max(maximize(prices, ind + 1, 1, fee, dp) + prices[ind],
                                     maximize(prices, ind + 1, 0, fee, dp));
    }
}
int maxProfit(vector<int> &prices, int fee)
{
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    return maximize(prices, 0, 1, fee, dp);
}

// TABULATION
int maxProfit(vector<int> &prices, int fee)
{
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
    for (int ind = prices.size() - 1; ind >= 0; ind--)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            if (canBuy)
            {
                dp[ind][canBuy] = max(dp[ind + 1][0] - prices[ind] - fee, dp[ind + 1][1]);
            }
            else
            {
                dp[ind][canBuy] = max(dp[ind + 1][1] + prices[ind], dp[ind + 1][0]);
            }
        }
    }

    return dp[0][1];
}