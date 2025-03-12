// https://leetcode.com/problems/next-greater-element-ii/
#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElements(vector<int> &nums)
{
    stack<int> st;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }
        st.push(nums[i]);
    }
    vector<int> ans(nums.size(), -1);
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            ans[i] = st.top();
        }
        st.push(nums[i]);
    }
    return ans;
}