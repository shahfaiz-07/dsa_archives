// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
#include<bits/stdc++.h>
using namespace std;
bool canAllocate(vector<int> &arr, int m, int mid)
{
    int pages = 0, s = 1;
    for (int book : arr)
    {
        if (pages + book > mid)
        {
            s++;
            if (s > m)
                return false;
            pages = book;
        }
        else
        {
            pages += book;
        }
    }
    return true;
}
int findPages(vector<int> &arr, int n, int m)
{
    // Write your code here.
    if (n < m)
    {
        return -1;
    }
    int l = 0, r = 0;
    for(int &ele: arr) {
        l = max(ele, l);
        r += ele;
    }
    int ans = -1;
    while (l <= r)
    {
        int mid = (r + l) / 2;
        if (canAllocate(arr, m, mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}