// https://leetcode.com/problems/course-schedule-ii/
#include<bits/stdc++.h>
using namespace std;
// DFS
bool dfsTopo(int curr, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inPath, stack<int> &st)
{
    if (inPath[curr])
        return true;
    if (visited[curr])
        return false;
    visited[curr] = true;
    inPath[curr] = true;
    for (int neighbor : adj[curr])
    {
        if (dfsTopo(neighbor, adj, visited, inPath, st))
        {
            return true;
        }
    }
    st.push(curr);
    inPath[curr] = false;
    return false;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    for (auto &pair : prerequisites)
    {
        adj[pair[1]].emplace_back(pair[0]);
    }
    vector<bool> visited(numCourses, false);
    vector<bool> inPath(numCourses, false);
    stack<int> st;
    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i] && dfsTopo(i, adj, visited, inPath, st))
        {
            return {};
        }
    }
    vector<int> ans(numCourses);
    for (int i = 0; i < numCourses; i++)
    {
        ans[i] = st.top();
        st.pop();
    }
    return ans;
}
// BFS
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    vector<int> inDegree(numCourses, 0);

    for (auto &pre : prerequisites)
    {
        adj[pre[1]].emplace_back(pre[0]);
        inDegree[pre[0]]++;
    }

    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < numCourses; i++)
    {
        if (!inDegree[i])
        {
            q.push(i);
            ans.emplace_back(i);
        }
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int &neighbor : adj[curr])
        {
            inDegree[neighbor]--;
            if (!inDegree[neighbor])
            {
                q.push(neighbor);
                ans.emplace_back(neighbor);
            }
        }
    }

    return ans.size() == adj.size() ? ans : vector<int>{};
}