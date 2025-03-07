// https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
#include<bits/stdc++.h>
using namespace std;
bool canPartition(vector<int> &arr, int k, int m)
{
    int time = 0, painters = 1;
    for (int &ele : arr)
    {
        if (time + ele > m)
        {
            painters++;
            if (painters > k)
                return false;
            time = ele;
        }
        else
        {
            time += ele;
        }
    }
    return true;
}

public:
int minTime(vector<int> &arr, int k)
{
    // code here
    // return minimum time
    int l = *max_element(arr.begin(), arr.end());
    int r = accumulate(arr.begin(), arr.end(), 0);
    int ans = r;
    while (l <= r)
    {
        int m = (r + l) / 2;
        if (canPartition(arr, k, m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return ans;
}