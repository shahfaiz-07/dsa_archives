// https://leetcode.com/problems/insert-interval/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> ans;
    int i = 0, n = intervals.size();
    while (i < n && newInterval[0] > intervals[i][1])
    {
        ans.emplace_back(intervals[i]);
        i++;
    }
    int start = (i != n) ? min(newInterval[0], intervals[i][0]) : newInterval[0];
    int end = newInterval[1];
    while (i < n && newInterval[1] >= intervals[i][0])
    {
        end = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back({start, end});
    while (i < n)
    {
        ans.emplace_back(intervals[i]);
        i++;
    }

    return ans;
}
int main(void) {
    
    return 0;
}