// https://www.geeksforgeeks.org/problems/topological-sort/1
#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> inDegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (int neighbor : adj[i])
        {
            inDegree[neighbor]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
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
        ans.push_back(curr);
        for (int neighbor : adj[curr])
        {
            inDegree[neighbor]--;
            if (!inDegree[neighbor])
            {
                q.push(neighbor);
            }
        }
    }
    return ans;
}
int main(void)
{

    return 0;
}