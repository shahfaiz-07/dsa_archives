// https://leetcode.com/problems/delete-operation-for-two-strings/
#include<bits/stdc++.h>
using namespace std;
// MEMOIZATION
int maximize(string &word1, string &word2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (word1[i] == word2[j])
    {
        return dp[i][j] = 1 + maximize(word1, word2, i - 1, j - 1, dp);
    }

    return dp[i][j] = max(maximize(word1, word2, i - 1, j, dp),
                          maximize(word1, word2, i, j - 1, dp));
}

int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
    return word1.length() + word2.length() - 2 * maximize(word1, word2, word1.length() - 1, word2.length() - 1, dp);
}
// TABULATION
int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));

    for (int i = 1; i <= word1.length(); i++)
    {
        for (int j = 1; j <= word2.length(); j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return word1.length() + word2.length() - 2 * dp[word1.length()][word2.length()];
}
int main(void) {
    
    return 0;
}