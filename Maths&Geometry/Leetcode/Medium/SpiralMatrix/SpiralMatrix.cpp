// https://leetcode.com/problems/spiral-matrix/
#include<bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int m = matrix.size(), n = matrix[0].size();
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    bool toRight = true, toDown = true, goHorizontal = true;
    while (ans.size() < m * n)
    {
        if (goHorizontal)
        {
            if (toRight)
            {
                // from left to right at top
                for (int i = left; i <= right; i++)
                {
                    ans.emplace_back(matrix[top][i]);
                }
                top++;
                toRight = false;
            }
            else
            {
                // from right to left at bottom
                for (int i = right; i >= left; i--)
                {
                    ans.emplace_back(matrix[bottom][i]);
                }
                bottom--;
                toRight = true;
            }
            goHorizontal = false;
        }
        else
        {
            if (toDown)
            {
                // from top to bottom at right
                for (int i = top; i <= bottom; i++)
                {
                    ans.emplace_back(matrix[i][right]);
                }
                right--;
                toDown = false;
            }
            else
            {
                // from bottom to top at left
                for (int i = bottom; i >= top; i--)
                {
                    ans.emplace_back(matrix[i][left]);
                }
                left++;
                toDown = true;
            }
            goHorizontal = true;
        }
    }
    return ans;
}