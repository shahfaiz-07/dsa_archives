// https://www.geeksforgeeks.org/problems/number-of-coins1824/1
#include<bits/stdc++.h>
using namespace std;
int minimumCoins(vector<int> &coins, int sum, vector<int> &dp)
{
    if (sum == 0)
        return 0;
    if (dp[sum])
    {
        return dp[sum];
    }
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        if (sum - coins[i] >= 0)
        {
            int val = minimumCoins(coins, sum - coins[i], dp);
            if (val != INT_MAX && val < mini)
            {
                mini = val + 1;
            }
        }
    }
    return dp[sum] = mini;
}
int minCoins(vector<int> &coins, int sum)
{
    // Your code goes here
    vector<int> dp(sum + 1, 0);
    int ret = minimumCoins(coins, sum, dp);
    return ret == INT_MAX ? -1 : ret;
}
int main(void) {
    
    return 0;
}