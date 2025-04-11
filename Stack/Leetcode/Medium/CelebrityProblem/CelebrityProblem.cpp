// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
#include<bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> &mat)
{
    // code here
    int n = mat.size();
    int low = 0, high = n - 1;
    while (low < high)
    {
        if (mat[low][high])
        {
            low++;
        }
        else if (mat[high][low])
        {
            high--;
        }
        else
        {
            low++;
            high--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i == low)
            continue;
        if (mat[low][i] == 1 || mat[i][low] == 0)
            return -1;
    }
    return low;
}