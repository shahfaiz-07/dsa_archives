// https://leetcode.com/problems/number-of-1-bits
#include<bits/stdc++.h>
using namespace std;
int hammingWeight(int n)
{
    // return __builtin_popcount(n)
    int c = 0;
    while (n)
    {
        n = n & (n - 1);
        c++;
    }
    return c;
}