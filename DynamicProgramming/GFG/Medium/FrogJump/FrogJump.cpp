// https://www.geeksforgeeks.org/problems/geek-jump/1
#include<bits/stdc++.h>
using namespace std;
//TABULATION
int minimumEnergy(vector<int> &height, int n)
{
    // Code here
    n = n - 1;
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return abs(height[1] - height[0]);
    }
    int prevMin2 = 0, prevMin1 = abs(height[1] - height[0]);
    for (int i = 2; i <= n; i++)
    {
        int from1 = prevMin1 + abs(height[i] - height[i - 1]);
        int from2 = prevMin2 + abs(height[i] - height[i - 2]);
        prevMin2 = prevMin1;
        prevMin1 = min(from1, from2);
    }
    return prevMin1;
}
//MEMOIZATION
int jump(vector<int> &height, int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int jump1 = jump(height, n - 1, dp) + abs(height[n] - height[n - 1]);
    int jump2 = INT_MAX;
    if (n > 1)
        jump2 = jump(height, n - 2, dp) + abs(height[n] - height[n - 2]);
    return dp[n] = min(jump1, jump2);
}

int minimumEnergy2(vector<int> &height, int n)
{
    // Code here
    vector<int> dp(n + 1, -1);
    return jump(height, n - 1, dp);
}
int main(void) {
    
    return 0;
}