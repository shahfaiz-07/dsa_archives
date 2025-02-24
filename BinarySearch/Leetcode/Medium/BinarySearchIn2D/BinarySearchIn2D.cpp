// https://leetcode.com/problems/search-a-2d-matrix

#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size(), n = matrix[0].size();
    int rl = 0, rr = m - 1;
    int rm = -1;
    while (rl <= rr)
    {
        rm = rr - (rr - rl) / 2;
        if (matrix[rm][0] <= target && matrix[rm][n - 1] >= target)
        {
            break;
        }
        else if (matrix[rm][0] > target)
        {
            rr--;
        }
        else
        {
            rl++;
        }
    }

    int cl = 0, cr = n - 1;

    while (cl <= cr)
    {
        int cm = cr - (cr - cl) / 2;

        if (matrix[rm][cm] == target)
        {
            return true;
        }
        else if (matrix[rm][cm] < target)
        {
            cl++;
        }
        else
        {
            cr--;
        }
    }
    return false;
}