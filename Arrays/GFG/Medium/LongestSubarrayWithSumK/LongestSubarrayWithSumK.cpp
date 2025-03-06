// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
#include<bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int> &arr, int k)
{
    // code here
    unordered_map<int, int> mp;
    mp[0] = -1;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        int x_k = sum - k;
        if (mp.count(x_k))
        {
            int len = i - mp[x_k];
            maxLen = max(len, maxLen);
        }
        mp.emplace(sum, i);
    }
    return maxLen;
}