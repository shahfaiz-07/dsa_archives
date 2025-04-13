// https://leetcode.com/problems/minimum-window-substring/
#include<bits/stdc++.h>
using namespace std;
string minWindow(string s, string t)
{
    unordered_map<char, int> mp;
    for (char c : t)
    {
        mp[c]++;
    }
    int l = 0, r = 0, start = -1, len = INT_MAX, c = 0;
    while (r < s.length())
    {
        int cnt = --mp[s[r]];
        if (cnt >= 0)
        {
            c++;
        }
        while (c == t.length())
        {
            if (r - l + 1 <= len)
            {
                start = l;
                len = r - l + 1;
            }
            int cnt2 = ++mp[s[l]];
            if (cnt2 == 1)
            {
                c--;
            }
            l++;
        }
        r++;
    }
    return start == -1 ? "" : s.substr(start, len);
}