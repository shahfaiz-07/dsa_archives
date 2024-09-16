// https://leetcode.com/problems/minimum-time-difference/
#include<bits/stdc++.h>
using namespace std;
int findMinDifference(vector<string> &timePoints)
{
    vector<int> tp(timePoints.size());
    for (int i = 0; i < timePoints.size(); i++)
    {
        string t1 = timePoints[i];
        int hour = stoi(t1.substr(0, 2));
        int min = stoi(t1.substr(3));
        tp[i] = hour * 60 + min;
    }
    sort(tp.begin(), tp.end());
    int diff = min(tp[tp.size() - 1] - tp[0], (1440 - tp[tp.size() - 1]) + tp[0]);
    for (int i = 0; i < timePoints.size() - 1; i++)
    {
        diff = min(diff, (tp[i + 1] - tp[i]));
    }
    return diff;
}
int main(void) {
    
    return 0;
}