// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
#include<bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int> &nums)
{
    int maxi = nums[0], maxL = 1, l = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > maxi)
        {
            maxi = nums[i];
            l = 1;
            maxL = 1;
        }
        else if (nums[i] == maxi)
        {
            l++;
            if (l > maxL)
                maxL = l;
        }
        else
            l = 0;
    }
    return maxL;
}
int main(void) {
    
    return 0;
}