// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
#include<bits/stdc++.h>
using namespace std;
double fractionalKnapsack(vector<int> &values, vector<int> &weights, int w)
{
    // Your code here
    vector<pair<int, int>> p;
    for (int i = 0; i < values.size(); i++)
    {
        p.emplace_back(make_pair(values[i], weights[i]));
    }

    sort(p.begin(), p.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return (double)b.first / b.second < (double)a.first / a.second; });

    double val = 0.0;
    int i = 0;
    while (i < values.size() && w != 0)
    {
        int value = p[i].first, wt = p[i].second;
        if (w - wt >= 0)
        {
            w = w - wt;
            val += value;
        }
        else
        {
            double vpw = (double)value / wt;
            val += w * vpw;
            w = 0;
        }
        i++;
    }
    return val;
}
int main(void) {
    
    return 0;
}