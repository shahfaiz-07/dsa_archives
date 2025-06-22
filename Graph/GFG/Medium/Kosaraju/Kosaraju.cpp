// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &adj, int curr, vector<bool> &visited, stack<int> &st)
{
    visited[curr] = true;
    for (int &neighbor : adj[curr])
    {
        if (!visited[neighbor])
        {
            dfs(adj, neighbor, visited, st);
        }
    }
    st.push(curr);
}

void dfs2(vector<vector<int>> &adj, int curr, vector<bool> &visited)
{
    visited[curr] = true;
    for (int &neighbor : adj[curr])
    {
        if (!visited[neighbor])
        {
            dfs2(adj, neighbor, visited);
        }
    }
}
int kosaraju(vector<vector<int>> &adj)
{
    // code here
    stack<int> st;
    int V = adj.size();
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(adj, i, visited, st);
        }
    }

    vector<vector<int>> rAdj(V, vector<int>());
    for (int i = 0; i < V; i++)
    {
        for (int neighbor : adj[i])
        {
            rAdj[neighbor].emplace_back(i);
        }
    }
    int c = 0;
    vector<bool> rVisited(V, false);
    while (!st.empty())
    {
        int ele = st.top();
        st.pop();
        if (!rVisited[ele])
        {
            dfs2(rAdj, ele, rVisited);
            c++;
        }
    }
    return c;
}