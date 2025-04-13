// https://leetcode.com/problems/fruit-into-baskets/
#include<bits/stdc++.h>
using namespace std;
int totalFruit(vector<int> &fruits)
{
    int l = 0, r = 0, ans = 0;
    unordered_map<int, int> mp;
    while (r < fruits.size())
    {
        mp[fruits[r]]++;
        while (mp.size() > 2)
        {
            int c = mp[fruits[l]];
            if (c == 1)
            {
                mp.erase(fruits[l]);
            }
            else
            {
                mp[fruits[l]] = c - 1;
            }
            l++;
        }
        ans = max(ans, r - l + 1);
        r++;
    }
    return ans;
}