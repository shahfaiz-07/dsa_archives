// https://leetcode.com/problems/car-fleet/
#include<bits/stdc++.h>
using namespace std;
int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    int n = position.size();
    vector<pair<int, int>> cars;
    for (int i = 0; i < n; i++)
    {
        cars.emplace_back(make_pair(position[i], speed[i]));
    }

    sort(cars.begin(), cars.end());

    double leaderTime = (target - cars[n - 1].first) * 1.0 / cars[n - 1].second;
    int fleetCount = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        double currTime = (target - cars[i].first) * 1.0 / cars[i].second;
        if (currTime > leaderTime)
        {
            leaderTime = currTime;
            fleetCount++;
        }
    }
    return fleetCount;
}