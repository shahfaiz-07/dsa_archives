// https://www.geeksforgeeks.org/problems/square-root/0
#include <bits/stdc++.h>
using namespace std;
long long int floorSqrt(long long int n)
{
    // Your code goes here
    long long int l = 0, u = n;
    long long int r = -1;
    while (l <= u)
    {
        long long int m = u - (u - l) / 2;
        if (m * m == n)
        {
            return m;
        }
        if ((m * m) < n)
        {
            r = m;
            l = m + 1;
        }
        else
        {
            u = m - 1;
        }
    }
    return r;
}
int main(void)
{

    return 0;
}