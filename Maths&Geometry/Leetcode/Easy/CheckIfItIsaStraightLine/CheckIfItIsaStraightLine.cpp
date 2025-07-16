// https://leetcode.com/problems/check-if-it-is-a-straight-line/

#include <bits/stdc++.h>
using namespace std;

bool checkStraightLine(vector<vector<int>> &coordinates)
{
    int dy = coordinates[0][1] - coordinates[1][1];
    int dx = coordinates[0][0] - coordinates[1][0];
    for (int i = 1; i < coordinates.size(); i++)
    {
        int dy1 = coordinates[0][1] - coordinates[i][1];
        int dx1 = coordinates[0][0] - coordinates[i][0];
        if (dy * dx1 != dy1 * dx)
            return false;
    }
    return true;
}