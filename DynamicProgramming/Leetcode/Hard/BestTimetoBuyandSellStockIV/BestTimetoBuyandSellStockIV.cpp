// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION
int maximize(vector<int> &prices, int ind, int canBuy, int c, vector<vector<vector<int>>> &dp)
{
    if (ind == prices.size() || c == 0)
        return 0;
    if (dp[ind][canBuy][c] != -1)
        return dp[ind][canBuy][c];
    if (canBuy)
    {
        return dp[ind][canBuy][c] = max(maximize(prices, ind + 1, 1, c, dp),
                                        maximize(prices, ind + 1, 0, c, dp) - prices[ind]);
    }
    return dp[ind][canBuy][c] = max(maximize(prices, ind + 1, 0, c, dp),
                                    maximize(prices, ind + 1, 1, c - 1, dp) + prices[ind]);
}

int maxProfit(int k, vector<int> &prices)
{
    vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return maximize(prices, 0, 1, k, dp);
}
// TABULATION
int maxProfit(int k, vector<int> &prices)
{
    vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
    for (int ind = prices.size() - 1; ind >= 0; ind--)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            for (int c = 1; c <= k; c++)
            {
                if (canBuy == 1)
                {
                    dp[ind][canBuy][c] = max(dp[ind + 1][1][c], dp[ind + 1][0][c] - prices[ind]);
                }
                else
                {
                    dp[ind][canBuy][c] = max(dp[ind + 1][0][c], dp[ind + 1][1][c - 1] + prices[ind]);
                }
            }
        }
    }
    return dp[0][1][k];
}