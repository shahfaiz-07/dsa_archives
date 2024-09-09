// https://leetcode.com/problems/house-robber/
#include<bits/stdc++.h>
using namespace std;
// TABULATION
int rob(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    if (nums.size() == 1)
    {
        return nums[0];
    }
    int prev1 = nums[0], prev2 = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int take = nums[i] + prev2;
        int notTake = prev1;
        prev2 = prev1;
        prev1 = max(take, notTake);
    }
    return prev1;
}
// MEMOIZATION
int jump(vector<int> &nums, int ind, vector<int> &dp)
{
    if (ind < 0)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    // rob
    int left = jump(nums, ind - 2, dp) + nums[ind];
    // leave
    int right = jump(nums, ind - 1, dp);
    dp[ind] = max(left, right);
    return dp[ind];
}
int rob2(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    if (nums.size() == 1)
    {
        return nums[0];
    }
    vector<int> dp(nums.size(), -1);
    return jump(nums, nums.size() - 1, dp);
}
int main(void) {
    
    return 0;
}