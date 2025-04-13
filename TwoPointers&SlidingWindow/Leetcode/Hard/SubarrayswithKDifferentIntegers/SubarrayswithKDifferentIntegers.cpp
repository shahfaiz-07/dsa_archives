// https://leetcode.com/problems/subarrays-with-k-different-integers/
#include<bits/stdc++.h>
using namespace std;
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return subarraysWithAtmostKDistinct(nums, k) -
           subarraysWithAtmostKDistinct(nums, k - 1);
}
int subarraysWithAtmostKDistinct(vector<int> &nums, int k)
{
    int l = 0, r = 0, ans = 0;
    unordered_map<int, int> mp;
    while (r < nums.size())
    {
        mp[nums[r]]++;
        while (mp.size() > k)
        {
            int c = mp[nums[l]];
            if (c == 1)
            {
                mp.erase(nums[l]);
            }
            else
            {
                mp[nums[l]] = c - 1;
            }
            l++;
        }
        ans += (r - l + 1);
        r++;
    }
    return ans;
}