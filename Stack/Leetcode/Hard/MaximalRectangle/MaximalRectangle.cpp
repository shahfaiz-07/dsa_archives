// https://leetcode.com/problems/maximal-rectangle/
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

public:
int maximalRectangle(vector<vector<char>> &matrix)
{
    vector<int> pref(matrix[0].size(), 0);
    for (int i = 0; i < matrix[0].size(); i++)
    {
        pref[i] = matrix[0][i] - '0';
    }
    int maxR = largestRectangleArea(pref);
    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            pref[j] = matrix[i][j] == '0' ? 0 : pref[j] + 1;
        }
        maxR = max(maxR, largestRectangleArea(pref));
    }
    return maxR;
}