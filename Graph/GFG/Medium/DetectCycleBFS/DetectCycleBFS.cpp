// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include<bits/stdc++.h>
using namespace std;
bool bfs(vector<int> adj[], vector<bool> &visited, int start)
{
    queue<pair<int, int>> q; // current node and previous node
    q.push(make_pair(start, start));
    visited[start] = true;
    while (!q.empty())
    {
        int curr = q.front().first, prev = q.front().second;
        q.pop();
        for (int neighbor : adj[curr])
        {
            if (visited[neighbor] && neighbor != prev)
            {
                return true;
            }
            else if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(make_pair(neighbor, curr));
            }
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
            if (bfs(adj, visited, i))
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