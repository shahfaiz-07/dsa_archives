// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
#include<bits/stdc++.h>
using namespace std;
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(V, false);

    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        int node = curr.second;
        if (visited[node])
            continue;
        int wt = curr.first;
        visited[node] = true;
        sum += wt;
        for (vector<int> &neighbor : adj[node])
        {
            int adjNode = neighbor[0], adjWt = neighbor[1];
            if (!visited[adjNode])
            {
                pq.push({adjWt, adjNode});
            }
        }
    }
    return sum;
}
int main(void) {
    
    return 0;
}