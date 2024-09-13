// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
#include<bits/stdc++.h>
using namespace std;
int minFlips(int a, int b, int c)
{
    int count = 0;
    while (a && b && c)
    {
        if (c & 1)
        {
            if (((b & 1) == 0) && ((a & 1) == 0))
            {
                count++;
            }
        }
        else
        {
            count += ((b & 1) + (a & 1));
        }
        c = c >> 1;
        b = b >> 1;
        a = a >> 1;
    }
    // b became 0, a and c remains
    while (a && c)
    {
        if ((a & 1) ^ (c & 1))
        {
            count++;
        }
        a = a >> 1;
        c = c >> 1;
    }
    // a became 0, b and c remains
    while (b && c)
    {
        if ((b & 1) ^ (c & 1))
        {
            count++;
        }
        b = b >> 1;
        c = c >> 1;
    }
    // c became 0 a and/or b remains - turn of all remaining bits
    while (a)
    {
        a = (a & (a - 1));
        count++;
    }
    while (b)
    {
        b = (b & (b - 1));
        count++;
    }
    // a and b became 0 c remains
    while (c)
    {
        c = (c & (c - 1));
        count++;
    }
    return count;
}
int main(void) {
    
    return 0;
}