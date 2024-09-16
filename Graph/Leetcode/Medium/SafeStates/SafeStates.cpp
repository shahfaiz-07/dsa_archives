#include <bits/stdc++.h>
using namespace std;
bool dfsSafe(vector<vector<int>> &graph, int curr, vector<bool> &visited, vector<int> &isSafe)
{
    if (isSafe[curr])
    {
        return isSafe[curr] == 1 ? true : false;
    }
    if (visited[curr])
        return false;
    if (graph[curr].size() == 0)
    {
        isSafe[curr] = 1;
        return true;
    }
    visited[curr] = true;
    for (int neighbor : graph[curr])
    {
        if (!dfsSafe(graph, neighbor, visited, isSafe))
        {
            isSafe[curr] = -1;
            return false;
        }
    }
    visited[curr] = false;
    isSafe[curr] = 1;
    return true;
}
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    vector<int> ans;
    vector<bool> visited(graph.size(), false);
    vector<int> isSafe(graph.size(), 0);
    // 0 is unknown, 1 is safe, -1 is unsafe
    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited[i] && isSafe[i] == 0)
            dfsSafe(graph, i, visited, isSafe);
    }
    for (int i = 0; i < graph.size(); i++)
    {
        if (isSafe[i] == 1)
        {
            ans.emplace_back(i);
        }
    }
    return ans;
}
int main(void)
{

    return 0;
}