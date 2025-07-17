// https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> P;
int MOD = 1e9 + 7;
long long solve(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
        return 1;
    vector<int> left, right;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] < nums[0])
            left.push_back(nums[i]);
        else
            right.push_back(nums[i]);
    }

    long long x = solve(left) % MOD, y = solve(right) % MOD;
    long long z = P[n - 1][left.size()];
    return (((x * y) % MOD) * z) % MOD;
}
int numOfWays(vector<int> &nums)
{
    int n = nums.size();
    P.resize(n);
    for (int i = 1; i < n; i++)
    {
        P[i] = vector<long long>(i + 1, 1);
        for (int j = 1; j < i; j++)
        {
            P[i][j] = (P[i - 1][j] + P[i - 1][j - 1]) % MOD;
        }
    }

    return (solve(nums) - 1) % MOD;
}