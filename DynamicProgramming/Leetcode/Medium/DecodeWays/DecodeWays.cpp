#include<bits/stdc++.h>
using namespace std;

// MEMOIZATION
int backtrack(string &s, int i, vector<int> &dp)
{
    if (i < 0)
    {
        return 1;
    }

    if (dp[i] != -1)
        return dp[i];

    if (s[i] == '0')
    {
        // you cannot proceed if it is the first index or if the previous index is > 2
        if (s[i - 1] == '0' || s[i - 1] > '2')
        {
            return dp[i] = 0;
        }
        // else you can only combine it with previous number
        return dp[i] = backtrack(s, i - 2, dp);
    }
    else
    {
        // take it as an individual number/letter
        int x = backtrack(s, i - 1, dp);
        int y = 0;
        // or combine with the previous only if it is less than two, current number is less than 7 and previous number is not zero
        if (i != 0 && s[i - 1] != '0')
        {
            int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (num <= 26)
                y = backtrack(s, i - 2, dp);
        }
        return dp[i] = x + y;
    }
}

int numDecodings(string s)
{
    if (s[0] == '0')
        return 0;
    vector<int> dp(s.length(), -1);
    return backtrack(s, s.length() - 1, dp);
}

// TABULATION
int numDecodings(string s)
{
    if (s[0] == '0')
        return 0;
    if (s.length() == 1)
        return 1;
    vector<int> dp(s.length());
    dp[0] = 1;
    if (s[1] == '0')
    {
        if (s[0] <= '2')
            dp[1] = 1;
        else
            return 0;
    }
    else
    {
        int initial = (s[0] - '0') * 10 + (s[1] - '0');
        if (initial <= 26)
        {
            dp[1] = 2;
        }
        else
        {
            dp[1] = 1;
        }
    }
    for (int i = 2; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            if (i == 0 || s[i - 1] > '2' || s[i - 1] == '0')
            {
                return 0;
            }
            dp[i] = dp[i - 2];
        }
        else
        {
            // as a single unit
            int x = dp[i - 1];
            int y = 0;
            // as a pair only if
            if (i != 0 && s[i - 1] != '0')
            {
                int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
                if (num <= 26)
                {
                    y = dp[i - 2];
                }
            }
            dp[i] = x + y;
        }
    }
    return dp[s.length() - 1];
}

// SPACE-OPTIMIZED
int numDecodings(string s)
{
    if (s[0] == '0')
        return 0;
    if (s.length() == 1)
        return 1;
    int prev2 = 1, prev1 = 1;
    if (s[1] == '0')
    {
        if (s[0] <= '2')
            prev1 = 1;
        else
            return 0;
    }
    else
    {
        int initial = (s[0] - '0') * 10 + (s[1] - '0');
        if (initial <= 26)
        {
            prev1 = 2;
        }
        else
        {
            prev1 = 1;
        }
    }
    for (int i = 2; i < s.length(); i++)
    {
        int curr = 0;
        if (s[i] == '0')
        {
            if (i == 0 || s[i - 1] > '2' || s[i - 1] == '0')
            {
                return 0;
            }
            curr = prev2;
        }
        else
        {
            // as a single unit
            int x = prev1;
            int y = 0;
            // as a pair only if
            if (i != 0 && s[i - 1] != '0')
            {
                int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
                if (num <= 26)
                {
                    y = prev2;
                }
            }
            curr = x + y;
        }
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}