// https://leetcode.com/problems/house-robber-ii/
#include<bits/stdc++.h>
using namespace std;
// TABULATION
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    if (n == 2)
    {
        return max(nums[0], nums[1]);
    }
    int prev1 = nums[0], prev2 = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int r = prev2 + nums[i];
        int l = prev1;
        prev2 = prev1;
        prev1 = max(r, l);
    }
    int r1 = prev1;
    prev1 = prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int r = prev2 + nums[i];
        int l = prev1;
        prev2 = prev1;
        prev1 = max(r, l);
    }
    return max(r1, prev1);
}
// TABULATION with dp array - works better but why?
int robx(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    if (n == 2)
    {
        return max(nums[0], nums[1]);
    }
    vector<int> dp(n);
    dp[0] = nums[0];
    for (int i = 1; i < n - 1; i++)
    {
        int r = INT_MIN;
        if (i > 1)
            r = dp[i - 2] + nums[i];
        int l = dp[i - 1];
        dp[i] = max(r, l);
    }
    int r1 = dp[n - 2];
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int r = nums[i];
        if (i > 1)
            r += dp[i - 2];
        int l = dp[i - 1];
        dp[i] = max(r, l);
    }
    int r2 = dp[n - 1];
    return max(r1, r2);
}
// MEMOIZATION
int robbing(vector<int> &nums, int i, bool includeStart, vector<int> &dp)
{
    if (i == 0)
    {
        if (includeStart)
        {
            return nums[0];
        }
        return 0;
    }
    if (i < 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    // rob
    int r = robbing(nums, i - 2, includeStart, dp) + nums[i];
    // leave
    int l = robbing(nums, i - 1, includeStart, dp);

    return dp[i] = max(r, l);
}

int rob2(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    vector<int> dp(nums.size(), -1);
    int r1 = robbing(nums, nums.size() - 1, false, dp);
    fill(dp.begin(), dp.end(), -1);
    int r2 = robbing(nums, nums.size() - 2, true, dp);
    return max(r1, r2);
}
int main(void) {
    
    return 0;
}