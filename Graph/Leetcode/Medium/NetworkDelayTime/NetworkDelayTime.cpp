// https://leetcode.com/problems/network-delay-time/
#include<bits/stdc++.h>
using namespace std;
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> adj(n + 1);

    for (vector<int> &edge : times)
    {
        adj[edge[0]].emplace_back(make_pair(edge[1], edge[2]));
    }

    vector<int> minTime(n + 1, INT_MAX);
    minTime[k] = 0;
    set<pair<int, int>> st;
    st.emplace(make_pair(0, k));

    while (!st.empty())
    {
        pair<int, int> curr = *(st.begin());
        int node = curr.second, time = curr.first;
        st.erase(curr);
        for (pair<int, int> &neighbor : adj[node])
        {
            int newTime = neighbor.second + time;

            if (minTime[neighbor.first] > newTime)
            {
                if (minTime[neighbor.first] != INT_MAX)
                {
                    st.erase(make_pair(minTime[neighbor.first], neighbor.first));
                }
                minTime[neighbor.first] = newTime;
                st.emplace(make_pair(newTime, neighbor.first));
            }
        }
    }

    int maxi = INT_MIN;
    // skip the 0
    for (int i = 1; i <= n; i++)
    {
        if (maxi < minTime[i])
        {
            maxi = minTime[i];
        }
    }
    return maxi == INT_MAX ? -1 : maxi;
}
int main(void) {
    
    return 0;
}