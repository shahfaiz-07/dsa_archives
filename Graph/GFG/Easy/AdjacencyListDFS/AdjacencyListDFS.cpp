// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
#include<bits/stdc++.h>
using namespace std;

void DFS(int start, vector<int> adj[], vector<int> &dfs, vector<int> &visited)
{
    visited[start] = 1;
    dfs.push_back(start);
    for (int neighbor : adj[start])
    {
        if (visited[neighbor] == 0)
        {
            DFS(neighbor, adj, dfs, visited);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> dfs;
    vector<int> visited(V, 0);
    DFS(0, adj, dfs, visited);
    return dfs;
}
int main(void) {
    
    return 0;
}