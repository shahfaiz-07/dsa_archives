// https://leetcode.com/problems/critical-connections-in-a-network/
#include <bits/stdc++.h>
using namespace std;

void dfs(int curr, int parent, vector<vector<int>> &adj, vector<int> &time, vector<int> &lowTime, vector<bool> &visited, int t, vector<vector<int>> &bridges)
{
    visited[curr] = true;
    time[curr] = lowTime[curr] = t;
    t++;
    for (int &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, curr, adj, time, lowTime, visited, t, bridges);
                lowTime[curr] = min(lowTime[curr], lowTime[neighbor]);

                if (time[curr] < lowTime[neighbor])
                {
                    bridges.push_back({curr, neighbor});
                }
            }
            else
            {
                lowTime[curr] = min(lowTime[curr], lowTime[neighbor]);
            }
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0], v = connections[i][1];
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> time(n, 0), lowTime(n, 0);
    vector<bool> visited(n, false);
    vector<vector<int>> bridges;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1, adj, time, lowTime, visited, 0, bridges);
        }
    }
    return bridges;
}