// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<int> adj[], vector<bool> &visited, int curr, int prev)
{
    if (visited[curr])
    {
        return true;
    }
    visited[curr] = true;
    for (int neighbor : adj[curr])
    {
        if (prev != neighbor && dfs(adj, visited, neighbor, curr))
        {
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(adj, visited, i, -1))
            {
                return true;
            }
        }
    }
    return false;
}
int main(void) {
    
    return 0;
}