// https://leetcode.com/problems/maximum-subarray/
#include<bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    int s = 0, maxSum = 0, maxNeg = INT_MIN;
    for (int &num : nums)
    {
        s += num;
        if (s <= 0)
        {
            maxNeg = max(s, maxNeg);
            s = 0;
        }
        maxSum = max(maxSum, s);
    }
    return maxSum == 0 ? maxNeg : maxSum;
}