// https://leetcode.com/problems/powx-n/
#include<bits/stdc++.h>
using namespace std;
unordered_map<long, double> hash;

double power(double x, long n)
{
    if (n == 0)
        return 1;
    double ans = hash[n];
    if (ans)
    {
        return ans;
    }
    if (n % 2 == 0)
    {
        ans = power(x * x, n / 2);
    }
    else
    {
        ans = x * power(x, n - 1);
    }
    hash[n] = ans;
    return ans;
}
double myPow(double x, int n)
{
    long nn = n;
    if (n < 0)
    {
        return 1 / power(x, -nn);
    }
    else
    {
        return power(x, nn);
    }
}