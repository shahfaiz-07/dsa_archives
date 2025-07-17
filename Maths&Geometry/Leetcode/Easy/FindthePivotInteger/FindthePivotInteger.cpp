// https://leetcode.com/problems/find-the-pivot-integer/
#include <bits/stdc++.h>
using namespace std;
// O(n)
int pivotInteger(int n)
{
    int rs = (n * (n + 1)) / 2, ls = 1;
    int ind = 1;
    while (ls <= rs)
    {
        if (ls == rs)
        {
            return ind;
        }
        ls += (ind + 1);
        rs -= ind;
        ind++;
    }
    return -1;
}
// O(log n)
int pivotInteger(int n)
{
    int t = (n * (n + 1)) / 2, l = 1, r = n;
    while (l <= r)
    {
        int m = (l + r) / 2;
        int ls = (m * (m + 1)) / 2, rs = t - ls + m;
        if (ls == rs)
        {
            return m;
        }
        if (ls < rs)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}
// O(1) + O(log n) for sqrt
// Solve for x:
// x * (x + 1) / 2 = (n * (n + 1) / 2) - (x * (x + 1) / 2) + x;
int pivotInteger(int n)
{
    double sq = sqrt((n * (n + 1)) / 2);
    return (int)sq == sq ? sq : -1;
}