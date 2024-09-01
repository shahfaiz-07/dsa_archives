// https://www.geeksforgeeks.org/problems/number-of-provinces/1
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &adj, int start, vector<bool> &visited)
{
    visited[start] = true;
    for (int i = 0; i < adj.size(); i++)
    {
        if (adj[start][i] && !visited[i])
        {
            dfs(adj, i, visited);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V)
{
    // code here
    vector<bool> visited(V, false);
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(adj, i, visited);
        }
    }
    return count;
}
int main(void) {
    
    return 0;
}