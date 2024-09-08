#include<bits/stdc++.h>
using namespace std;
// Using Tabulation
int climbStairs(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int n1 = 0, n2 = 1, ways = 0;
    for (int i = n; i >= 1; i--)
    {
        ways = n1 + n2;
        n1 = n2;
        n2 = ways;
    }
    return ways;
}

// Using Memoization
int climb(int n, vector<int> &dp)
{
    if (n <= 2)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = climb(n - 1, dp) + climb(n - 2, dp);
}
int climbStairs2(int n)
{
    vector<int> dp(n + 1, -1);
    return climb(n, dp);
}

int main(void) {
    cout << climbStairs(40) << "\n";
    cout << climbStairs2(40);
    return 0;
}