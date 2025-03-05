// https://leetcode.com/problems/reverse-bits/
#include<bits/stdc++.h>
using namespace std;
uint32_t reverseBits(uint32_t n)
{
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((n >> i) & 1)
            ans = ans | (1 << (31 - i));
    }
    return ans;
}