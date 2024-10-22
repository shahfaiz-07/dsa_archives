// https://leetcode.com/problems/merge-intervals/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
         {
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0]; });
    vector<vector<int>> ans;
    int start = intervals[0][0], end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++)
    {
        int curStart = intervals[i][0], curEnd = intervals[i][1];
        if (curStart <= end)
        {
            if (curEnd > end)
                end = curEnd;
        }
        else
        {
            ans.push_back({start, end});
            start = curStart;
            end = curEnd;
        }
    }
    ans.push_back({start, end});
    return ans;
}
int main(void) {
    
    return 0;
}