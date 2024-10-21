// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int x, int y)
    {
        int upX = findParent(x), upY = findParent(y);
        if (upX == upY)
            return; // same component
        if (size[upX] < size[upY])
        {
            parent[upX] = upY;
            size[upY] += size[upX];
        }
        else
        {
            parent[upY] = upX;
            size[upX] += size[upY];
        }
    }
};
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < V; i++)
    {
        for (auto edge : adj[i])
        {
            int wt = edge[1], node = edge[0];
            edges.emplace_back(make_pair(wt, make_pair(i, node)));
        }
    }
    sort(edges.begin(), edges.end());
    DisjointSet ds(V);
    int totalWt = 0;
    for (auto edge : edges)
    {
        int wt = edge.first, u = edge.second.first, v = edge.second.second;
        if (ds.findParent(u) != ds.findParent(v))
        {
            totalWt += wt;
            ds.unionBySize(u, v);
        }
    }
    return totalWt;
}
int main(void) {
    
    return 0;
}