// https://leetcode.com/problems/sliding-window-maximum/
#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;
    int l = 0, r = 0;
    while (r < nums.size())
    {
        while (!dq.empty() && nums[dq.back()] <= nums[r])
        {
            dq.pop_back();
        }
        dq.push_back(r);
        if (dq.front() < l)
        {
            dq.pop_front();
        }
        if (r - l + 1 == k)
        {
            ans.push_back(nums[dq.front()]);
            l++;
        }
        r++;
    }
    return ans;
}