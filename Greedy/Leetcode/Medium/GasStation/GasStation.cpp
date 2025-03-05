// https://leetcode.com/problems/gas-station/
#include<bits/stdc++.h>
using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{   
    // total gas should always be more than or equal to the total cost
    if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
    {
        return -1;
    }
    int start = 0, total = 0;
    // not very intuitive but if the total gas - cost difference becomes less than 0, it means that starting at any previous station, you cannot complete the circle, so the very first index through which you can reach the end with total >= 0 will be your start index
    for (int i = 0; i < gas.size(); i++)
    {
        total += gas[i] - cost[i];

        if (total < 0)
        {
            total = 0;
            start = i + 1;
        }
    }
    return start;
}