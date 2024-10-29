// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
#include<bits/stdc++.h>
using namespace std;
int longestCommonSubstr(string str1, string str2)
{
    // your code here
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxi = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxi = max(maxi, dp[i][j]);
            }
        }
    }
    return maxi;
}
int main(void) {
    
    return 0;
}