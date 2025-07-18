// https://leetcode.com/problems/pascals-triangle/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    ans.push_back({1});
    for (int i = 1; i < numRows; i++)
    {
        vector<int> row;
        row.push_back(1);
        for (int j = 1; j < i; j++)
        {
            row.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
        }
        row.push_back(1);
        ans.push_back(row);
    }
    return ans;
}

int nCr(int n, int r) {
    int res = 1;
    // (n) * (n-1) * ... * (n-r+1) / 1 * 2 * ... * r
    for(int i=0; i<r; i++) {
        res = res*(n-i)/(i+1);
    }
    return res;
}

int main() {
    cout << nCr(10, 3) << endl;
    return 0;
}