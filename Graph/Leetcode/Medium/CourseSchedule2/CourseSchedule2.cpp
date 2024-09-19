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
        ans[count++] = curr;
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
        return {};
    return ans;
}
int main(void) {
    
    return 0;
}