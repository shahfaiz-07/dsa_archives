// https://leetcode.com/problems/making-a-large-island/
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
int valueOf(int n, int x, int y)
{
    return x * n + y;
}
bool isValid(int newr, int newc, int n)
{
    return newr >= 0 && newr < n && newc >= 0 && newc < n;
}
int largestIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    DisjointSet ds(n * n);
    // step - 1
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 0)
                continue;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            for (int ind = 0; ind < 4; ind++)
            {
                int newr = row + dr[ind];
                int newc = col + dc[ind];
                if (isValid(newr, newc, n) && grid[newr][newc] == 1)
                {
                    int nodeNo = row * n + col;
                    int adjNodeNo = newr * n + newc;
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
        }
    }
    // step 2
    int mx = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 1)
                continue;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            set<int> components;
            for (int ind = 0; ind < 4; ind++)
            {
                int newr = row + dr[ind];
                int newc = col + dc[ind];
                if (isValid(newr, newc, n))
                {
                    if (grid[newr][newc] == 1)
                    {
                        components.insert(ds.findPar(newr * n + newc));
                    }
                }
            }
            int sizeTotal = 0;
            for (auto it : components)
            {
                sizeTotal += ds.size[it];
            }
            mx = max(mx, sizeTotal + 1);
        }
    }
    for (int cellNo = 0; cellNo < n * n; cellNo++)
    {
        mx = max(mx, ds.size[ds.findPar(cellNo)]);
    }
    return mx;
}