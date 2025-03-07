// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
#include<bits/stdc++.h>
using namespace std;
int shipWithinDays(vector<int> &weights, int days)
{
    int l = 0, r = 0;

    for (int w : weights)
    {
        l = max(l, w);
        r += w;
    }
    int ans = r;
    while (l <= r)
    {
        int m = r - (r - l) / 2;
        int cap = 0, day = 1;
        bool can = true;
        for (int &ele : weights)
        {
            if (cap + ele > m)
            {
                day++;
                if (day > days)
                {
                    can = false;
                    break;
                }
                cap = ele;
            }
            else
            {
                cap += ele;
            }
        }
        if (can)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}