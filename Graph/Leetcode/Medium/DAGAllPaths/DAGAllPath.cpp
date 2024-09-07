// https://leetcode.com/problems/all-paths-from-source-to-target/description/
#include<bits/stdc++.h>
using namespace std;
void traverse(vector<vector<int>> &graph, int curr, vector<int> &visited, vector<int> &path, vector<vector<int>> &paths)
{
    if (curr == graph.size() - 1)
    {
        path.emplace_back(curr);
        paths.emplace_back(path);
        return;
    }
    if (visited[curr])
    {
        return;
    }
    visited[curr] = 1;
    path.emplace_back(curr);
    for (int neighbor : graph[curr])
    {
        if (!visited[neighbor])
        {
            traverse(graph, neighbor, visited, path, paths);
            path.pop_back();
        }
    }
    visited[curr] = 0;
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<vector<int>> paths;
    vector<int> path;
    vector<int> visited(graph.size(), 0);
    traverse(graph, 0, visited, path, paths);
    return paths;
}
int main(void) {
    
    return 0;
}