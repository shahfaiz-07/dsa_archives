// https://leetcode.com/problems/edit-distance/
#include<bits/stdc++.h>
using namespace std;
// MEMOIZATION
int minimize(string &word1, string &word2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
        return 0;
    if (j < 0)
    {
        return i + 1;
    }
    if (i < 0)
    {
        return j + 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (word1[i] == word2[j])
    {
        return dp[i][j] = minimize(word1, word2, i - 1, j - 1, dp);
    }

    // insert
    int m1 = minimize(word1, word2, i, j - 1, dp);

    // replace
    int m2 = minimize(word1, word2, i - 1, j - 1, dp);

    // delete
    int m3 = minimize(word1, word2, i - 1, j, dp);
    return dp[i][j] = min(m1, min(m2, m3)) + 1;
}

int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
    return minimize(word1, word2, word1.size() - 1, word2.size() - 1, dp);
}

// TABULATION
int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 1; i < dp[0].size(); i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= word1.size(); i++)
    {
        dp[i][0] = i;
        for (int j = 1; j <= word2.size(); j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                // insert
                int m1 = dp[i][j - 1];

                // replace
                int m2 = dp[i - 1][j - 1];

                // delete
                int m3 = dp[i - 1][j];
                dp[i][j] = min(m1, min(m2, m3)) + 1;
            }
        }
    }
    return dp[word1.size()][word2.size()];
}

// SPACE OPTIMIZED
int minDistance(string word1, string word2)
{
    vector<int> dp(word2.size() + 1, 0);

    for (int i = 1; i < dp.size(); i++)
    {
        dp[i] = i;
    }

    for (int i = 1; i <= word1.size(); i++)
    {
        vector<int> temp(word2.size() + 1, 0);
        temp[0] = i;
        for (int j = 1; j <= word2.size(); j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                temp[j] = dp[j - 1];
            }
            else
            {
                // insert
                int m1 = temp[j - 1];

                // replace
                int m2 = dp[j - 1];

                // delete
                int m3 = dp[j];
                temp[j] = min(m1, min(m2, m3)) + 1;
            }
        }
        dp = temp;
    }
    return dp[word2.size()];
}
int main(void) {
    
    return 0;
}