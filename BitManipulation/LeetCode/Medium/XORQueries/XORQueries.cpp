// https://leetcode.com/problems/xor-queries-of-a-subarray/
#include<bits/stdc++.h>
using namespace std;
vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    vector<int> ans(queries.size(), 0);
    vector<int> xors(arr.size(), 0);
    xors[0] = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        xors[i] = arr[i] ^ xors[i - 1];
    }
    for (int i = 0; i < queries.size(); i++)
    {
        int L = queries[i][0];
        int R = queries[i][1];
        ans[i] = xors[R] ^ (L == 0 ? 0 : xors[L - 1]);
    }
    return ans;
}
int main(void) {
    
    return 0;
}