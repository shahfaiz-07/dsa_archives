// https://www.geeksforgeeks.org/problems/topological-sort/1
#include<bits/stdc++.h>
using namespace std;
void dfsTopo(vector<int> adj[], int curr, vector<bool> &visited, stack<int> &st)
{
    visited[curr] = true;
    for (int neighbor : adj[curr])
    {
        if (!visited[neighbor])
        {
            dfsTopo(adj, neighbor, visited, st);
        }
    }
    st.push(curr);
}

// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<bool> visited(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfsTopo(adj, i, visited, st);
        }
    }
    vector<int> ans(V);
    for (int i = 0; i < V; i++)
    {
        ans[i] = st.top();
        st.pop();
    }
    return ans;
}
int main(void) {
    
    return 0;
}