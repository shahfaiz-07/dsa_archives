// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
#include<bits/stdc++.h>
using namespace std;
// DFS
void topoSort(vector<vector<pair<int, int>>> &adj, int curr, vector<bool> &visited, stack<int> &st)
{
    visited[curr] = true;
    for (pair<int, int> &neighbor : adj[curr])
    {
        if (!visited[neighbor.first])
        {
            topoSort(adj, neighbor.first, visited, st);
        }
    }
    st.push(curr);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    // code here
    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < M; i++)
    {
        adj[edges[i][0]].emplace_back(make_pair(edges[i][1], edges[i][2]));
    }
    stack<int> st;
    vector<bool> visited(N, false);
    topoSort(adj, 0, visited, st);
    vector<int> dist(N, INT_MAX);
    dist[0] = 0;
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        for (pair<int, int> &neighbor : adj[curr])
        {
            if (dist[curr] + neighbor.second < dist[neighbor.first])
            {
                dist[neighbor.first] = dist[curr] + neighbor.second;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == INT_MAX)
            dist[i] = -1;
    }
    return dist;
}
int main(void) {
    
    return 0;
}