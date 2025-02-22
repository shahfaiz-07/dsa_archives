// https://leetcode.com/problems/container-with-most-water/
#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int l = 0, r = height.size() - 1;
    int maxArea = 0;
    while (l < r)
    {
        int area = (r - l) * ((height[l] < height[r]) ? height[l] : height[r]);
        maxArea = max(area, maxArea);

        if (height[l] < height[r])
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return maxArea;
}