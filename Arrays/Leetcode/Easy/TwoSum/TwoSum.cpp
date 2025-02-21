// https://leetcode.com/problems/two-sum/
#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    mp[nums[0]] = -1;
    for (int i = 1; i < nums.size(); i++)
    {
        int t = mp[target - nums[i]];
        if (t)
        {
            if (t == -1)
            {
                return {0, i};
            }
            else
            {
                return {i, t};
            }
        }
        else
        {
            mp[nums[i]] = i;
        }
    }
    return {0, 0};
}