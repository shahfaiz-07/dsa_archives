// https://leetcode.com/problems/non-overlapping-intervals/
#include<bits/stdc++.h>
using namespace std;
// Approach - 1
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b)
         { return a[0] < b[0]; });

    int l = 0, r = 1, count = 0;
    while (r < intervals.size())
    {
        int ce = intervals[l][1], ne = intervals[r][1],
            ns = intervals[r][0];
        if (ce <= ns)
        {
            l = r;
            r++;
        }
        else if (ce <= ne)
        {
            r++;
            count++;
        }
        else
        {
            l = r;
            r++;
            count++;
        }
    }
    return count;
}
// Approach - 2
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b)
         { return a[0] < b[0]; });

    int i = 1, count = 0;
    vector<int> last_interval = intervals[0];
    while (i < intervals.size())
    {
        int ce = intervals[i][1], cs = intervals[i][0], le = last_interval[1];
        if (le <= cs)
        {
            // safe
            last_interval = intervals[i];
            i++;
        }
        else if (le <= ce)
        {
            i++;
            count++;
        }
        else
        {
            last_interval = intervals[i];
            i++;
            count++;
        }
    }
    return count;
}
int main(void) {
    
    return 0;
}