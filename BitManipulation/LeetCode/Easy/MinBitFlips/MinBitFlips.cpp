// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
#include <bits/stdc++.h>
using namespace std;
int minBitFlips(int start, int goal)
{
    int count = 0;
    while (start && goal)
    {
        if ((start & 1) ^ (goal & 1))
        {
            count++;
        }
        start = start >> 1;
        goal = goal >> 1;
    }
    while (start)
    {
        start = start & (start - 1);
        count++;
    }
    while (goal)
    {
        goal = goal & (goal - 1);
        count++;
    }
    return count;
}
int main(void)
{
    cout << minBitFlips(10, 7);
    return 0;
}