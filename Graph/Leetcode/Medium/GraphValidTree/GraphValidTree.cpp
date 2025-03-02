// https://neetcode.io/problems/valid-tree
// https://leetcode.com/problems/graph-valid-tree/description/

#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &adj, vector<bool> &visited, int curr, int prev)
{
    if (visited[curr])
    {
        return true;
    }

    visited[curr] = true;
    for (int &neighbor : adj[curr])
    {
        if (neighbor != prev && dfs(adj, visited, neighbor, curr))
        {
            return true;
        }
    }
    return false;
}
bool validTree(int n, vector<vector<int>> &edges)
{
    vector<bool> visited(n, false);
    vector<vector<int>> adj(n);

    for (auto &edge : edges)
    {
        adj[edge[0]].emplace_back(edge[1]);
        adj[edge[1]].emplace_back(edge[0]);
    }

    if (dfs(adj, visited, 0, -1))
        return false;

    for (int i = 1; i < n; i++)
    {
        if (!visited[i])
            return false;
    }

    return true;
}