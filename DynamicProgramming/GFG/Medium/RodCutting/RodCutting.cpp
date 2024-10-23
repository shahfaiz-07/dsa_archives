// https://www.geeksforgeeks.org/problems/rod-cutting0840/1
#include<bits/stdc++.h>
using namespace std;
// MEMOIZATION
int maximize(int price[], int L, int index, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        return L * price[0];
    }
    if (dp[index][L] != -1)
    {
        return dp[index][L];
    }
    int cut = 0;
    if (L >= index + 1)
    {
        cut = maximize(price, L - (index + 1), index, dp) + price[index];
    }
    int notCut = maximize(price, L, index - 1, dp);
    return dp[index][L] = max(cut, notCut);
}

int cutRod(int price[], int n)
{
    // code here
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return maximize(price, n, n - 1, dp);
}

// TABULATION
int cutRod(int price[], int n)
{
    // code here
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * price[0];
    }

    for (int index = 1; index < n; index++)
    {
        for (int L = 1; L <= n; L++)
        {
            int cut = 0;
            if (L >= index + 1)
            {
                cut = dp[index][L - (index + 1)] + price[index];
            }
            int notCut = dp[index - 1][L];
            dp[index][L] = max(cut, notCut);
        }
    }
    return dp[n - 1][n];
}
int main(void) {
    
    return 0;
}