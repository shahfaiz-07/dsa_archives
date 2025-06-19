// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
#include <bits/stdc++.h>
using namespace std;

class Disjoint
{
public:
    vector<int> par, size;
    Disjoint(int V)
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
        int up_u = findPar(u), up_v = findPar(v);

        if (up_u == up_v)
            return;

        if (size[up_u] < size[up_v])
        {
            par[up_u] = par[up_v];
            size[up_v] += size[up_u];
        }
        else
        {
            par[up_v] = par[up_u];
            size[up_u] += size[up_v];
        }
    }
};
int removeStones(vector<vector<int>> &stones)
{
    // to connect stones here we treat every row as an individual node and every column as an individual node.
    // for 5*4 matrix
    // rows - 0 1 2 3 4, cols - 5(0th col) 6 7 8
    // col = col + row
    // if a stone belongs to 0th row and 0th col, we combine nodes 0 and 5

    int n = stones.size();
    int r = 0, c = 0;
    for (auto it : stones)
    {
        r = max(it[0], r);
        c = max(it[1], c);
    }

    r += 1;
    c += 1;

    Disjoint ds(r + c);
    vector<bool> visited(r + c, false);
    for (auto it : stones)
    {
        ds.unionBySize(it[0], it[1] + r);
        visited[it[0]] = true;
        visited[it[1] + r] = true;
    }

    int count = 0;
    for (int i = 0; i < r + c; i++)
    {
        if (visited[i] && ds.findPar(i) == i)
        {
            count++;
        }
    }

    return n - count;
}