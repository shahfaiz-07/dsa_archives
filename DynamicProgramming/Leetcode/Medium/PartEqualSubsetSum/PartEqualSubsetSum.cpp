// https://leetcode.com/problems/partition-equal-subset-sum/
#include<bits/stdc++.h>
using namespace std;
bool partSum(vector<int> &nums, int index, int target, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return true;
    }
    if (index < 0 || target < 0)
        return false;
    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }
    if (partSum(nums, index - 1, target - nums[index], dp))
    {
        return dp[index][target] = true;
    }
    if (partSum(nums, index - 1, target, dp))
    {
        return dp[index][target] = true;
    }
    return dp[index][target] = false;
}

bool canPartition(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1)
        return false;
    vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, 0));
    return partSum(nums, nums.size() - 1, sum / 2, dp);
}
int main(void) {
    
    return 0;
}