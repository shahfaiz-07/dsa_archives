// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
#include<bits/stdc++.h>
using namespace std;
int findPlatform(vector<int> &arr, vector<int> &dep)
{
    // Your code here
    sort(begin(arr), end(arr));
    sort(begin(dep), end(dep));
    int count = 0, maxCount = 0;
    int r1 = 0, r2 = 0;
    while (r1 < arr.size() && r2 < arr.size())
    {
        if (dep[r2] < arr[r1])
        {
            count--;
            r2++;
        }
        else
        {
            count++;
            maxCount = max(maxCount, count);
            r1++;
        }
    }
    return maxCount;
}
int main(void) {
    
    return 0;
}