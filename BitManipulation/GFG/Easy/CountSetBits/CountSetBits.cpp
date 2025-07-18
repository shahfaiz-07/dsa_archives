// https://www.geeksforgeeks.org/problems/set-bits0143/1
#include <bits/stdc++.h>
using namespace std;

int setBits(int n)
{
    // Write Your Code here
    int c = 0;
    while (n != 0)
    {
        n = n & (n - 1);
        c++;
    }
    return c;
}