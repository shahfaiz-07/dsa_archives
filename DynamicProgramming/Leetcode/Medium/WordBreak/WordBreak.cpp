// https://leetcode.com/problems/word-break/
#include<bits/stdc++.h>
using namespace std;
bool partition(string s, int index, vector<string> &wordDict, vector<int> &dp)
{
    if (index == -1)
    {
        return true;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    string str = "";
    for (int i = index; i >= 0; i--)
    {
        str = s[i] + str;
        if (find(wordDict.begin(), wordDict.end(), str) != wordDict.end() && partition(s, i - 1, wordDict, dp))
        {
            return dp[index] = true;
        }
    }
    return dp[index] = false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    vector<int> dp(s.size(), -1);
    return partition(s, s.size() - 1, wordDict, dp);
}
int main(void) {
    
    return 0;
}