// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
#include<bits/stdc++.h>
using namespace std;
int kthElement(vector<int> &a, vector<int> &b, int k)
{
    // code here
    int i1 = 0, i2 = 0;
    int ind = 0;
    while (i1 < a.size() && i2 < b.size())
    {
        int currEle = 0;
        if (a[i1] < b[i2])
        {
            currEle = a[i1];
            i1++;
        }
        else
        {
            currEle = b[i2];
            i2++;
        }
        ind++;
        if (ind == k)
        {
            return currEle;
        }
    }
    while (i1 < a.size())
    {
        int currEle = a[i1];
        i1++;
        ind++;
        if (ind == k)
        {
            return currEle;
        }
    }
    while (i2 < b.size())
    {
        int currEle = b[i2];
        i2++;
        ind++;
        if (ind == k)
        {
            return currEle;
        }
    }
    return -1;
}