// https://leetcode.com/problems/longest-common-subsequence/
#include<bits/stdc++.h>
using namespace std;
// MEMOIZATION
int maximize(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (text1[i] == text2[j])
    {
        return dp[i][j] = 1 + maximize(text1, text2, i - 1, j - 1, dp);
    }

    return dp[i][j] = max(maximize(text1, text2, i - 1, j, dp),
                          maximize(text1, text2, i, j - 1, dp));
}

int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
    return maximize(text1, text2, text1.length() - 1, text2.length() - 1, dp);
}
// TABULATION
int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));

    for (int i = 1; i <= text1.length(); i++)
    {
        for (int j = 1; j <= text2.length(); j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[text1.length()][text2.length()];
}
int main(void) {
    
    return 0;
}