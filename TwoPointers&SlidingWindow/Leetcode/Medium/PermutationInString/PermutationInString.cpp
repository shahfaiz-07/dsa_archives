// https://leetcode.com/problems/permutation-in-string/

#include<bits/stdc++.h>
using namespace std;
bool checkInclusion(string s1, string s2)
{
    if (s2.length() < s1.length())
        return false;
    vector<int> hashMap(26, 0);
    for (int i = 0; i < s1.length(); i++)
    {
        hashMap[s1[i] - 'a']++;
    }
    int l = 0, r = 0;
    // fix window size
    vector<int> s2Map(26, 0);
    while (r < s2.length())
    {
        s2Map[s2[r] - 'a']++;
        if ((r - l + 1) < s1.length())
        {
            r++;
        }
        else
        {
            if (s2Map == hashMap)
            {
                return true;
            }
            s2Map[s2[l] - 'a']--;
            l++;
            r++;
        }
    }

    return false;
}