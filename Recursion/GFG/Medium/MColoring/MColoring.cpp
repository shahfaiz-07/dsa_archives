// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
#include<bits/stdc++.h>
using namespace std;
bool possible(vector<vector<int>> &adj, int node, int c, vector<int> &color)
{
    for (int &neighbor : adj[node])
    {
        if (color[neighbor] == c)
            return false;
    }
    return true;
}
bool canColor(int m, vector<vector<int>> &adj, int node, vector<int> &color)
{
    if (node == adj.size())
    {
        return true;
    }
    for (int i = 1; i <= m; i++)
    {
        if (possible(adj, node, i, color))
        {
            color[node] = i;
            if (canColor(m, adj, node + 1, color))
            {
                return true;
            }
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(int v, vector<pair<int, int>> &edges, int m)
{
    // code here
    vector<vector<int>> adj(v);
    for (auto &edge : edges)
    {
        adj[edge.first].emplace_back(edge.second);
        adj[edge.second].emplace_back(edge.first);
    }
    vector<int> color(v, 0);
    return canColor(m, adj, 0, color);
}
int main(void) {
    
    return 0;
}