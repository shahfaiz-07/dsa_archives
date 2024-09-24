// https://leetcode.com/problems/find-a-peak-element-ii/
#include<bits/stdc++.h>
using namespace std;
int maxInColumn(vector<vector<int>> &mat, int j)
{
    int maxR = 0;
    for (int i = 1; i < mat.size(); i++)
    {
        if (mat[maxR][j] < mat[i][j])
        {
            maxR = i;
        }
    }
    return maxR;
}

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int n = mat[0].size();
    int l = 0, u = n - 1;
    while (l <= u)
    {
        int mid = u - (u - l) / 2;
        int maxR = maxInColumn(mat, mid);
        int left = mid == 0 ? -1 : mat[maxR][mid - 1];
        int right = mid == n - 1 ? -1 : mat[maxR][mid + 1];
        if (mat[maxR][mid] > left && mat[maxR][mid] > right)
        {
            return {maxR, mid};
        }
        else if (mat[maxR][mid] > left)
        {
            l = mid + 1;
        }
        else
        {
            u = mid - 1;
        }
    }
    return {-1, -1};
}
int main(void) {
    
    return 0;
}