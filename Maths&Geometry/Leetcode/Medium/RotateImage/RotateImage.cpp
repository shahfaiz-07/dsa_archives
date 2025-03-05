// https://leetcode.com/problems/rotate-image/
#include<bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &matrix)
{
    // reverse the columns and transpose
    int u = 0, l = matrix.size() - 1;
    while (u < l)
    {
        swap(matrix[u], matrix[l]);
        u++;
        l--;
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}