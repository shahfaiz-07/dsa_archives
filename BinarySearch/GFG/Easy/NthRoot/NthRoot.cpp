// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
#include <bits/stdc++.h>
using namespace std;
long long int findPower(long long int x, long long int y, int m)
{

    long long int ans = 1;
    while (y > 0)
    {
        if (y & 1)
        {
            ans *= x;
            if (ans > m)
                return INT_MAX;
            y -= 1;
        }
        else
        {
            x = x * x;
            if (x > m)
                return INT_MAX;
            y /= 2;
        }
    }
    return ans > 0 ? ans : INT_MAX;
}
int NthRoot(int n, int m)
{
    // Code here.
    long long int l = 1, u = m;
    while (l <= u)
    {
        long long int mid = u - (u - l) / 2;
        long long int ans = findPower(mid, n, m);
        if (ans == m)
        {
            return mid;
        }
        else if (ans < m)
        {
            l = mid + 1;
        }
        else
        {
            u = mid - 1;
        }
    }
    return -1;
}
int main(void)
{

    return 0;
}