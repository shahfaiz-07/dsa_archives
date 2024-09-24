// https://leetcode.com/problems/find-peak-element/
#include<bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int> &nums)
{
    int l = 0, u = nums.size() - 1;
    if (nums.size() == 1)
    {
        return 0;
    }
    while (l <= u)
    {
        int mid = u - (u - l) / 2;
        int left = mid == 0 ? INT_MIN : nums[mid - 1];
        int right = mid == nums.size() - 1 ? INT_MIN : nums[mid + 1];
        if (nums[mid] >= left && nums[mid] >= right)
        {
            return mid;
        }
        else if (nums[mid] > left)
        {
            l = mid + 1;
        }
        else
        {
            u = mid - 1;
        }
    }
    return -1;
}
int main(void) {
    
    return 0;
}