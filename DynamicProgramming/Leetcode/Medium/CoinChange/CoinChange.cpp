// https://leetcode.com/problems/coin-change/
#include<bits/stdc++.h>
using namespace std;
// MEMOIZATION
int minCoins(vector<int> &coins, int amount, vector<int> &dp)
{
    if (amount == 0)
    {
        return 0;
    }
    if (dp[amount])
        return dp[amount];
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        if (amount - coins[i] >= 0)
        {
            int val = minCoins(coins, amount - coins[i], dp);
            if (val != INT_MAX && mini > val + 1)
            {
                mini = val + 1;
            }
        }
    }
    return dp[amount] = mini;
}

int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, 0);
    int ret = minCoins(coins, amount, dp);
    if (ret == INT_MAX)
        return -1;
    return ret;
}
// TABULATION
int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, 0);
    for (int j = 1; j <= amount; j++)
    {
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            if (j - coins[i] >= 0)
            {
                int val = dp[j - coins[i]];
                if (val != INT_MAX && mini > val + 1)
                {
                    mini = val + 1;
                }
            }
        }
        dp[j] = mini;
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
int main(void) {
    
    return 0;
}