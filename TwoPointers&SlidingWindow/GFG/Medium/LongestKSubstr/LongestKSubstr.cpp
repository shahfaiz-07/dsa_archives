// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
#include<bits/stdc++.h>
using namespace std;
int longestKSubstr(string &s, int k)
{
    // your code here
    vector<int> hash(26, 0);
    int l = 0, r = 0, ans = -1;
    while (r < s.length())
    {
        hash[s[r] - 'a']++;
        if (hash[s[r] - 'a'] == 1)
        {
            k--;
        }
        while (k == -1)
        {
            hash[s[l] - 'a']--;
            if (hash[s[l] - 'a'] == 0)
                k++;
            l++;
        }
        if (k == 0)
            ans = max(ans, r - l + 1);
        r++;
    }
    return ans;
}