// https://leetcode.com/problems/largest-rectangle-in-histogram/
#include<bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int n = heights.size();
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            int ind = st.top();
            st.pop();
            int left = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[ind] * (i - left - 1));
        }
        st.push(i);
    }
    while (!st.empty())
    {
        int ind = st.top();
        st.pop();
        int left = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, heights[ind] * (n - left - 1));
    }
    return maxArea;
}