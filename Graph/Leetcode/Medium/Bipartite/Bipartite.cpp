// https://leetcode.com/problems/is-graph-bipartite/
#include<bits/stdc++.h>
using namespace std;
// DFS
bool colorGraph(vector<vector<int>> &graph, int curr, int prevColor, vector<int> &visited)
{
    if (visited[curr])
    {
        return visited[curr] != prevColor;
    }
    visited[curr] = -prevColor;
    for (int neighbor : graph[curr])
    {
        if (!colorGraph(graph, neighbor, -prevColor, visited))
        {
            return false;
        }
    }
    return true;
}
// BFS
bool colorGraph(vector<vector<int>> &graph, int start, vector<int> &visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        int curr = q.front(), prevColor = visited[curr];
        q.pop();
        for (int neighbor : graph[curr])
        {
            if (visited[neighbor] && visited[neighbor] == prevColor)
            {
                return false;
            }
            if (!visited[neighbor])
            {
                visited[neighbor] = -prevColor;
                q.push(neighbor);
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    vector<int> visited(graph.size(), 0);
    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited[i])
        {
            if (!colorGraph(graph, i, visited))
            {
                return false;
            }
        }
    }
    return true;
}
int main(void) {
    
    return 0;
}