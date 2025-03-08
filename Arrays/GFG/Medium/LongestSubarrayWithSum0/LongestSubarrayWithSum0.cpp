// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
#include<bits/stdc++.h>
using namespace std;
int maxLen(vector<int> &arr)
{
    // code here
    unordered_map<int, int> hash;
    hash[0] = -1;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (hash.count(sum))
        {
            int len = i - hash[sum];
            maxLen = max(maxLen, len);
        }
        hash.emplace(sum, i);
    }
    return maxLen;
}