// https://leetcode.com/problems/subarray-sum-equals-k/
#include<bits/stdc++.h>
using namespace std;
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> hash;
    int sum = 0, c = 0;
    hash.emplace(0, 1);
    for (int &ele : nums)
    {
        sum += ele;
        int x_k = sum - k;
        int val = hash[x_k];
        if (val)
        {
            c += val;
        }
        hash[sum]++;
    }
    return c;
}