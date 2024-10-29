// https://leetcode.com/problems/wildcard-matching
#include<bits/stdc++.h>
using namespace std;
// MEMOIZATION
bool matched(string &s, string &p, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
    {
        return true;
    }
    if (j < 0)
    {
        return false;
    }
    if (i < 0)
    {
        while (j >= 0 && p[j] == '*')
        {
            j--;
        }
        return j == -1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    char ch1 = s[i], ch2 = p[j];
    if (ch2 != '*')
    {
        if (ch2 == '?')
        {
            return dp[i][j] = matched(s, p, i - 1, j - 1, dp);
        }
        return dp[i][j] = ch1 == ch2 && matched(s, p, i - 1, j - 1, dp);
    }
    return dp[i][j] = matched(s, p, i - 1, j, dp) || matched(s, p, i, j - 1, dp);
}

bool isMatch(string s, string p)
{
    vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
    return matched(s, p, s.length() - 1, p.length() - 1, dp) == 1;
}
// TABULATION
bool isMatch(string s, string p)
{
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= p.size() && p[i - 1] == '*'; i++)
    {
        dp[0][i] = true;
    }

    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= p.size(); j++)
        {
            char ch1 = s[i - 1], ch2 = p[j - 1];
            if (ch2 != '*')
            {
                if (ch2 == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = ch1 == ch2 && dp[i - 1][j - 1];
                }
            }
            else
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }
    return dp[s.size()][p.size()];
}
int main(void) {
    
    return 0;
}