// https://leetcode.com/problems/find-eventual-safe-states/
#include <bits/stdc++.h>
using namespace std;
// DFS
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

// BFS
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    vector<vector<int>> revGraph(graph.size());
    vector<int> inDegree(graph.size());
    for (int i = 0; i < graph.size(); i++)
    {
        inDegree[i] = graph[i].size();
        for (int &neighbor : graph[i])
        {
            revGraph[neighbor].emplace_back(i);
        }
    }
    queue<int> q;
    for (int i = 0; i < revGraph.size(); i++)
    {
        if (!inDegree[i])
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans.emplace_back(curr);
        for (int &neighbor : revGraph[curr])
        {
            inDegree[neighbor]--;
            if (!inDegree[neighbor])
            {
                q.push(neighbor);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main(void)
{

    return 0;
}