#include <bits/stdc++.h>
using namespace std;

// M1 - divide consecutively by 4

// M2 - log(n) should be integer

bool isPowerOfFour(int n)
{
    if (n <= 0)
        return false;
    double d = log(n) / log(4);
    return ((int)d) == d;
}

// M3 - Property : 1. n is Power of 2, 2. n-1 is divisible by 3

bool isPowerOfFour(int n)
{
    if (n <= 0)
        return false;
    // power of 2
    if ((n & (n - 1)) != 0)
        return false;
    // n - 1 divisible by 3
    return (n - 1) % 3 == 0;
}