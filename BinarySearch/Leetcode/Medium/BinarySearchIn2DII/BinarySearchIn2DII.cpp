// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size(), n = matrix[0].size();
    int ri = 0, ci = n - 1;

    while (ri < m && ci >= 0)
    {
        if (matrix[ri][ci] == target)
        {
            return true;
        }
        if (matrix[ri][ci] < target)
        {
            ri++;
        }
        else
        {
            ci--;
        }
    }
    return false;
}