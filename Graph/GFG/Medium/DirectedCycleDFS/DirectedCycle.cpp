// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
#include<bits/stdc++.h>
using namespace std;
bool dfsCycle(vector<int> adj[], vector<bool> &visited, vector<bool> &currentGraph, int curr)
{
    if (currentGraph[curr])
        return true;
    if (visited[curr])
        return false;
    currentGraph[curr] = true;
    visited[curr] = true;
    for (int neighbor : adj[curr])
    {
        if (dfsCycle(adj, visited, currentGraph, neighbor))
        {
            return true;
        }
    }
    currentGraph[curr] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<bool> visited(V, false);
    vector<bool> currentGraph(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dfsCycle(adj, visited, currentGraph, i))
        {
            return true;
        }
    }
    return false;
}
int main(void) {
    
    return 0;
}