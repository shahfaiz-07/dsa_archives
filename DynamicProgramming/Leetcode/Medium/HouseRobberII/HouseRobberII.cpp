// https://leetcode.com/problems/house-robber-ii/
#include<bits/stdc++.h>
using namespace std;
// SPACE-OPTIMIZED
int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    // flag 1 means we rob the first house so can't rob the second, stored in dp[1]
    vector<vector<int>> dp(2, vector<int>(2, 0));
    dp[0][1] = nums[1];
    dp[1][0] = nums[0];
    dp[1][1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++)
    {
        int curr0 = max(nums[i] + dp[0][0], dp[0][1]);
        dp[0][0] = dp[0][1];
        dp[0][1] = curr0;
        if (i < nums.size() - 1)
        {
            int curr1 = max(nums[i] + dp[1][0], dp[1][1]);
            dp[1][0] = dp[1][1];
            dp[1][1] = curr1;
        }
    }

    return max(dp[0][1], dp[1][1]);
}
// TABULATION
int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    // flag 1 means we rob the first house so can't rob the second, stored in dp[1]
    vector<vector<int>> dp(2, vector<int>(nums.size(), 0));
    dp[0][1] = nums[1];
    dp[1][0] = nums[0];
    dp[1][1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++)
    {
        dp[0][i] = max(nums[i] + dp[0][i - 2], dp[0][i - 1]);
        if (i < nums.size() - 1)
            dp[1][i] = max(nums[i] + dp[1][i - 2], dp[1][i - 1]);
    }

    return max(dp[0][nums.size() - 1], dp[1][nums.size() - 2]);
}
// MEMOIZATION
int memoize(vector<int> &nums, int i, vector<vector<int>> &dp, int flag)
{
    // flag 1 means you robbed nth house and can't rob 0th house, you have to go till first
    // flag 0 means you didn't rob nth house and can go till 0th house
    if (i < flag)
    {
        return 0; // for flag 1 we return 0 when i becomes 0
    }

    if (dp[flag][i] != -1)
        return dp[flag][i];

    return dp[flag][i] = max(nums[i] + memoize(nums, i - 2, dp, flag), memoize(nums, i - 1, dp, flag));
}

int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    // flag 1 means we rob the first house so can't rob the second, stored in dp[1]
    vector<vector<int>> dp(2, vector<int>(nums.size(), -1));
    return max(memoize(nums, nums.size() - 1, dp, 1), memoize(nums, nums.size() - 2, dp, 0));
}