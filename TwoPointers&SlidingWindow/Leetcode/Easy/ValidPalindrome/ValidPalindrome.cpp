// https://leetcode.com/problems/valid-palindrome
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int l = 0, r = s.length() - 1;
    while (l < r)
    {
        while (l < r && !isalnum(s[l]))
        {
            l++;
        }
        while (l < r && !isalnum(s[r]))
        {
            r--;
        }

        char chl = s[l] < 97 ? s[l] + 32 : s[l];
        char chr = s[r] < 97 ? s[r] + 32 : s[r];

        if (chl != chr)
        {
            return false;
        }

        l++;
        r--;
    }

    return true;
}