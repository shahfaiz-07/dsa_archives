// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
#include<bits/stdc++.h>
using namespace std;
int findSumDiv(vector<int> &nums, double k)
{
    int sum = 0;
    for (int ele : nums)
    {
        sum += (int)ceil(ele / k);
    }
    return sum;
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    int u = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (u < nums[i])
        {
            u = nums[i];
        }
    }
    int l = 1;
    while (l <= u)
    {
        int m = u - (u - l) / 2;
        int sum = findSumDiv(nums, m);

        if (sum <= threshold)
        {
            u = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}
int main(void) {
    
    return 0;
}