// https://leetcode.com/problems/course-schedule/
#include<bits/stdc++.h>
using namespace std;
// Using DFS
bool dfsTopo(int curr, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inPath)
{
    if (inPath[curr])
        return true;
    if (visited[curr])
        return false;
    visited[curr] = true;
    inPath[curr] = true;
    for (int neighbor : adj[curr])
    {
        if (dfsTopo(neighbor, adj, visited, inPath))
        {
            return true;
        }
    }
    inPath[curr] = false;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    for (auto &pair : prerequisites)
    {
        adj[pair[1]].emplace_back(pair[0]);
    }
    vector<bool> visited(numCourses, false);
    vector<bool> inPath(numCourses, false);
    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i] && dfsTopo(i, adj, visited, inPath))
        {
            return false;
        }
    }
    return true;
}

// BFS
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    vector<int> inDegree(numCourses, 0);
    for (auto &pair : prerequisites)
    {
        adj[pair[1]].emplace_back(pair[0]);
        inDegree[pair[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (!inDegree[i])
        {
            q.push(i);
        }
    }
    vector<int> ans(numCourses);
    int count = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        count++;
        for (int &neighbor : adj[curr])
        {
            inDegree[neighbor]--;
            if (!inDegree[neighbor])
            {
                q.push(neighbor);
            }
        }
    }
    if (count != numCourses)
        return false;
    return true;
}
int main(void) {
    
    return 0;
}