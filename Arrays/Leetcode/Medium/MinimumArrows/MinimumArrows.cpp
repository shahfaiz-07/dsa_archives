// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
#include<bits/stdc++.h>
using namespace std;

// concept of overlapping after sort (intervals)
int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b)
         { return a[0] < b[0]; });
    int i = 1, count = 0;
    vector<int> last_point = points[0];
    while (i < points.size())
    {
        int ce = points[i][1], cs = points[i][0], le = last_point[1];
        if (le < cs)
        {
            // require difference arrows
            last_point = points[i];
            i++;
        }
        else if (le <= ce)
        {
            i++;
            count++;
        }
        else
        {
            last_point = points[i];
            i++;
            count++;
        }
    }
    return points.size() - count;
}
int main(void) {
    
    return 0;
}