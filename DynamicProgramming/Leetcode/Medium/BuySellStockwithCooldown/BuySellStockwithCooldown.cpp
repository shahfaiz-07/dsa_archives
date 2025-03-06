// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
#include<bits/stdc++.h>
using namespace std;
int profit(int i, vector<int> &prices, bool canBuy, vector<vector<int>> &dp)
{
    if (i >= prices.size())
        return 0;
    if (dp[i][canBuy] != -1)
        return dp[i][canBuy];
    int cooldown = profit(i + 1, prices, canBuy, dp);
    if (canBuy)
    {
        int bought = profit(i + 1, prices, !canBuy, dp) - prices[i];
        return dp[i][canBuy] = max(cooldown, bought);
    }
    int sold = profit(i + 2, prices, !canBuy, dp) + prices[i];
    return dp[i][canBuy] = max(cooldown, sold);
}

int maxProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    return profit(0, prices, true, dp);
}