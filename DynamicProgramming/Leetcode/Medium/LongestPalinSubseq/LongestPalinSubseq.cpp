#include<bits/stdc++.h>
using namespace std;
// MEMOIZATION
int maximize(string &s, int i, int j, vector<vector<int>> &dp)
{
    if (i >= s.length() || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s[i] == s[j])
    {
        dp[i][j] = maximize(s, i + 1, j - 1, dp) + 1;
    }
    else
    {
        dp[i][j] = max(maximize(s, i + 1, j, dp), maximize(s, i, j - 1, dp));
    }
    return dp[i][j];
}

int longestPalindromeSubseq(string s)
{
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
    return maximize(s, 0, s.length() - 1, dp);
}
// TABULATION
int longestPalindromeSubseq(string s)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, 0));
    string s2 = "";
    for (int i = 0; i < s.length(); i++)
    {
        s2 = s[i] + s2;
    }
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= s.length(); j++)
        {
            if (s[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[s.length()][s.length()];
}
int main(void) {
    
    return 0;
}