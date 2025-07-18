// https://www.geeksforgeeks.org/problems/rotation4723/1
#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr)
{
    // Code Here
    int l = 0, r = arr.size() - 1;
    while (l < r)
    {
        int m = (l + r) / 2;
        // go towards the unsorted half
        if (arr[m] <= arr[r])
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}