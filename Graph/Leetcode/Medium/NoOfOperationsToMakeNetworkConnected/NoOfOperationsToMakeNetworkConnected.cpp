// https://leetcode.com/problems/number-of-operations-to-make-network-connected/
#include<bits/stdc++.h>

class DisjointSet
{
public:
    vector<int> par;
    vector<int> size;
    DisjointSet(int V)
    {
        for (int i = 0; i < V; i++)
        {
            par.emplace_back(i);
            size.emplace_back(1);
        }
    }

    int findPar(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = findPar(par[x]);
    }

    void unionBySize(int u, int v)
    {
        int up_u = findPar(u);
        int up_v = findPar(v);

        if (up_v == up_u)
            return;

        if (size[up_u] < size[up_v])
        {
            par[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else
        {
            par[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};

public:
int makeConnected(int n, vector<vector<int>> &connections)
{
    int xtraEdges = 0;
    DisjointSet ds(n);
    for (vector<int> &edge : connections)
    {
        if (ds.findPar(edge[0]) == ds.findPar(edge[1]))
        {
            xtraEdges++;
        }
        else
        {
            ds.unionBySize(edge[0], edge[1]);
        }
    }
    int components = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds.par[i] == i)
        {
            components++;
        }
    }
    int ans = components - 1;
    return xtraEdges >= ans ? ans : -1;
}