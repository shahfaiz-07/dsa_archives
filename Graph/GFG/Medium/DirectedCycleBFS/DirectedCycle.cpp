// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
#include<bits/stdc++.h>
using namespace std;
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    queue<int> q;
    vector<int> inDegree(V);
    for (int i = 0; i < V; i++)
    {
        for (int &ele : adj[i])
        {
            inDegree[ele]++;
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    int count = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        count++;
        for (int &neighbor : adj[curr])
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }
    return count != V;
}
int main(void) {
    
    return 0;
}