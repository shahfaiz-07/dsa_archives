// https://leetcode.com/problems/3sum/description/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size() && nums[i] <= 0; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        else
        {
            vector<int> val;
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int s = nums[l] + nums[r] + nums[i];
                if (s == 0)
                {
                    ans.push_back({nums[l], nums[r], nums[i]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1])
                    {
                        l++;
                    }
                }
                else if (s < 0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
    }
    return ans;
}