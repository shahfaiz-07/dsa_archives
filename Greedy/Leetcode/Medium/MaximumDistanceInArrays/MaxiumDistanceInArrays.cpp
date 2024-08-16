// https://leetcode.com/problems/maximum-distance-in-arrays/
#include<bits/stdc++.h>
using namespace std;
int maxDistance(vector<vector<int>> &arrays)
{
    int up_max = arrays[0].back(), low_min = arrays[0][0], diff = 0;

    for (int i = 1; i < arrays.size(); i++)
    {
        diff = max({diff, abs(up_max - arrays[i][0]), abs(low_min - arrays[i].back())});
        up_max = max(up_max, arrays[i].back());
        low_min = min(low_min, arrays[i][0]);
    }
    return diff;
}
int main(void) {
    
    return 0;
}