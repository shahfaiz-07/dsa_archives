// https://leetcode.com/problems/missing-number/
#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int> &nums)
{
    int XOR = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        XOR = XOR ^ nums[i];
    }
    for (int i = 0; i <= nums.size(); i++)
    {
        XOR = XOR ^ i;
    }
    return XOR;
}