// https://leetcode.com/problems/minimum-time-visiting-all-points/
#include <bits/stdc++.h>
using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>> &points)
{
    int t = 0;
    for (int i = 1; i < points.size(); i++)
    {
        int dx = abs(points[i][0] - points[i - 1][0]);
        int dy = abs(points[i][1] - points[i - 1][1]);
        t += max(dx, dy);
    }
    return t;
}