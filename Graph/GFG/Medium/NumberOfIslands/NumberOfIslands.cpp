// https://www.geeksforgeeks.org/problems/number-of-islands/0
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> par, size;
    DisjointSet(int V)
    {
        for (int i = 0; i < V; i++)
        {
            par.emplace_back(i);
            size.emplace_back(0);
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
int valueOf(int row, int col, int x, int y)
{
    return x * col + y;
}
vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
{
    // code here

    DisjointSet ds(n * m);
    int count = 0;
    vector<vector<int>> dels = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> ans;
    for (vector<int> &op : operators)
    {
        int val = valueOf(n, m, op[0], op[1]);
        if (ds.size[val] == 0)
        {
            count++;
            ds.size[val] = 1;
            for (vector<int> &del : dels)
            {
                int x = op[0] + del[0], y = op[1] + del[1];
                if (x >= 0 && y >= 0 && x < n && y < m)
                {
                    int val1 = valueOf(n, m, x, y);
                    if (ds.size[val1] != 0)
                    {
                        if (ds.findPar(val) != ds.findPar(val1))
                        {
                            count--;
                            ds.unionBySize(val, val1);
                        }
                    }
                }
            }
        }
        ans.emplace_back(count);
    }
    return ans;
}