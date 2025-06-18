// https://leetcode.com/problems/accounts-merge/

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
vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    unordered_map<string, int> mp;
    int V = accounts.size();
    DisjointSet ds(V);
    for (int i = 0; i < V; i++)
    {
        for (int j = 1; j < accounts[i].size(); j++)
        {
            string &email = accounts[i][j];
            auto search = mp.find(email);
            if (search != mp.end())
            {
                ds.unionBySize(i, search->second);
            }
            else
            {
                mp[email] = i;
            }
        }
    }

    vector<vector<string>> t(V, vector<string>());
    for (auto &entry : mp)
    {
        int val = ds.findPar(entry.second);
        t[val].emplace_back(entry.first);
    }

    vector<vector<string>> ans;
    for (int i = 0; i < V; i++)
    {
        if (t[i].size() == 0)
            continue;
        vector<string> temp;
        sort(t[i].begin(), t[i].end());
        temp.emplace_back(accounts[i][0]);
        for (string &ele : t[i])
        {
            temp.emplace_back(ele);
        }
        ans.emplace_back(temp);
    }
    return ans;
}