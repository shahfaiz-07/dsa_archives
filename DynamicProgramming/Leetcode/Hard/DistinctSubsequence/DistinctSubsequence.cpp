// https://leetcode.com/problems/distinct-subsequences/
#include<bits/stdc++.h>
using namespace std;
// MEMOIZATION
int count(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int p = 0;
    if (s[i] == t[j])
    {
        p = count(s, t, i - 1, j - 1, dp);
    }
    int n = count(s, t, i - 1, j, dp);
    return dp[i][j] = p + n;
}

int numDistinct(string s, string t)
{
    vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
    return count(s, t, s.length() - 1, t.length() - 1, dp);
}

// TABULATION
int numDistinct(string s, string t)
{
    const int MOD = 1e9 + 7;
    vector<vector<long long>> dp(s.size() + 1, vector<long long>(t.size() + 1, 0));
    for (int i = 0; i < dp.size(); i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= t.length(); j++)
        {
            long long p = 0;
            if (s[i - 1] == t[j - 1])
            {
                p = dp[i - 1][j - 1];
            }
            long long n = dp[i - 1][j];
            dp[i][j] = (p + n) % MOD;
        }
    }

    return dp[s.length()][t.length()];
}
// SPACE OPTIMIZED
int numDistinct(string s, string t)
{
    const int MOD = 1e9 + 7;
    vector<int> dp(t.size() + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= s.length(); i++)
    {
        vector<int> temp(t.size() + 1, 0);
        temp[0] = 1;
        for (int j = 1; j <= t.length(); j++)
        {
            int p = 0;
            if (s[i - 1] == t[j - 1])
            {
                p = dp[j - 1];
            }
            int n = dp[j];
            temp[j] = (p + n) % MOD;
        }
        dp = temp;
    }

    return dp[t.length()];
}
int main(void) {
    
    return 0;
}