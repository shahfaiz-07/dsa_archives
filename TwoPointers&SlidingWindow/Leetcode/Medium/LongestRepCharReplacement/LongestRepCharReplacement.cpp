// https://leetcode.com/problems/longest-repeating-character-replacement/

#include<bits/stdc++.h>
using namespace std;
int characterReplacement(string s, int k)
{
    vector<int> hashMap(26, 0);

    int l = 0, r = 0, maxLen = 0, maxFreq = 0;
    while (r < s.length())
    {
        hashMap[s[r] - 'A']++;
        maxFreq = max(maxFreq, hashMap[s[r] - 'A']);
        // window_size - maxFreq character gives length of changed character
        if ((r - l + 1) - maxFreq > k)
        {
            // more than k letters are to be flipped
            hashMap[s[l] - 'A']--;
            l++;
        }
        else
        {
            maxLen = max(r - l + 1, maxLen);
        }
        r++;
    }
    return maxLen;
}