// https://leetcode.com/problems/non-overlapping-intervals/
#include<bits/stdc++.h>
using namespace std;
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });
    int freeTime = INT_MIN, count = intervals.size();
    for (auto &interval : intervals)
    {
        int start = interval[0], end = interval[1];
        if (freeTime <= start)
        {
            freeTime = end;
            count--;
        }
    }
    return count;
}
int main(void) {
    
    return 0;
}