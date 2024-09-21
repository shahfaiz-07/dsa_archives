// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    // code here
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++)
    {
        adj[edges[i][0]].emplace_back(edges[i][1]);
        adj[edges[i][1]].emplace_back(edges[i][0]);
    }
    queue<pair<int, int>> q;
    vector<int> dist(N, -1);
    dist[src] = 0;
    q.push({src, 0});
    while (!q.empty())
    {
        int curr = q.front().first;
        int distance = q.front().second;
        q.pop();
        for (int &neighbor : adj[curr])
        {
            if (dist[neighbor] == -1)
            {
                dist[neighbor] = distance + 1;
                q.push({neighbor, distance + 1});
            }
        }
    }
    return dist;
}
int main(void) {
    
    return 0;
}