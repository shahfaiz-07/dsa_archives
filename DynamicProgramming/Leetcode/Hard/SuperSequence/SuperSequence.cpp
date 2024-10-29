// https://leetcode.com/problems/shortest-common-supersequence/
#include<bits/stdc++.h>
using namespace std;
string shortestCommonSupersequence(string str1, string str2)
{
    vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, 0));

    for (int i = 1; i <= str1.length(); i++)
    {
        for (int j = 1; j <= str2.length(); j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string ans = "";
    int i = str1.length(), j = str2.length();
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            ans = str1[i - 1] + ans;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans = str1[i - 1] + ans;
            i--;
        }
        else
        {
            ans = str2[j - 1] + ans;
            j--;
        }
    }
    while (i > 0)
    {
        ans = str1[i - 1] + ans;
        i--;
    }
    while (j > 0)
    {
        ans = str2[j - 1] + ans;
        j--;
    }
    return ans;
}
int main(void) {
    
    return 0;
}