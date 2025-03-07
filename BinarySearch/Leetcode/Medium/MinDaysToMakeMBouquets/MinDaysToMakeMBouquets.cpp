// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
#include<bits/stdc++.h>
using namespace std;
int minDays(vector<int> &bloomDay, int m, int k)
{
    int val = *max_element(bloomDay.begin(), bloomDay.end());
    int l = 0, r = val;
    int ans = -1;
    while (l <= r)
    {
        int mid = r - (r - l) / 2;
        int c = 0, flowers = 0;
        bool found = false;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= mid)
            {
                c++;
                if (c == k)
                {
                    flowers++;
                    if (flowers == m)
                    {
                        found = true;
                        break;
                    }
                    c = 0;
                }
            }
            else
            {
                c = 0;
            }
        }
        if (found)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}