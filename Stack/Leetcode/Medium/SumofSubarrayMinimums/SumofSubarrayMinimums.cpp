// https://leetcode.com/problems/sum-of-subarray-minimums/
#include<bits/stdc++.h>
using namespace std;
void getNSEPSE(vector<int> &arr, vector<vector<int>> &nsePSE)
{
    int n = arr.size();
    stack<int> stNSE;
    stack<int> stPSE;
    // first row contains NSE
    // second PSE(incl. equals)
    for (int i = 0; i < n; i++)
    {
        // NSE
        while (!stNSE.empty() && arr[stNSE.top()] >= arr[n - i - 1])
        {
            stNSE.pop();
        }
        nsePSE[0][n - i - 1] = stNSE.empty() ? n : stNSE.top();
        stNSE.push(n - i - 1);

        // PSE
        while (!stPSE.empty() && arr[stPSE.top()] > arr[i])
        {
            stPSE.pop();
        }
        nsePSE[1][i] = stPSE.empty() ? -1 : stPSE.top();
        stPSE.push(i);
    }
}

int sumSubarrayMins(vector<int> &arr)
{
    const int MOD = (int)(1e9 + 7);
    vector<vector<int>> nsePSE(2, vector<int>(arr.size()));
    getNSEPSE(arr, nsePSE);
    long ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = (ans + ((long)arr[i] * (nsePSE[0][i] - i) % MOD) * (i - nsePSE[1][i]) % MOD) % MOD;
    }
    return (int)(ans % MOD);
}