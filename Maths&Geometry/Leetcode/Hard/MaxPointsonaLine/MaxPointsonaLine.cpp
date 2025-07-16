// https://leetcode.com/problems/max-points-on-a-line/
#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>> &points)
{
    int n = points.size();
    if (n == 1)
        return 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<double, int> mp;
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            double dy = points[j][1] - points[i][1];
            double dx = points[j][0] - points[i][0];

            double slope = dx == 0 ? DBL_MAX : dy / dx;
            mp[slope]++;
            ans = max(ans, mp[slope] + 1);
        }
    }

    return ans;
}