// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<bits/stdc++.h>
using namespace std;
int search(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int m = r - (r - l) / 2;
        if (nums[m] == target)
        {
            return m;
        }
        // find sorted side
        if (nums[l] <= nums[m])
        {
            // left side is sorted
            if (nums[l] <= target && target < nums[m])
            {
                // no. in sorted side
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        else
        {
            // right side is sorted
            if (nums[m] < target && target <= nums[r])
            {
                // no. in sorted side
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
    }
    return -1;
}