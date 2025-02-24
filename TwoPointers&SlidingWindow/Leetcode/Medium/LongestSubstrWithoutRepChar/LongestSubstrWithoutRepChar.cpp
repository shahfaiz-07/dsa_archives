// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    vector<bool> hashSet(256, false);
    int l = 0, r = 0;
    int maxLen = 0;
    while (r < s.length())
    {
        if (hashSet[s[r]])
        {
            hashSet[s[l]] = false;
            l++;
        }
        else
        {
            hashSet[s[r]] = true;
            if (r - l + 1 > maxLen)
            {
                maxLen = max(r - l + 1, maxLen);
            }
            r++;
        }
    }
    return maxLen;
}