// // https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/
#include <bits/stdc++.h>
using namespace std;

bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
{
    if (sx == fx && sy == fy)
    {
        return t != 1;
    }
    int dx = abs(sx - fx);
    int dy = abs(sy - fy);
    return t >= max(dx, dy);
}