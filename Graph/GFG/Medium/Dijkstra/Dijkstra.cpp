// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include<bits/stdc++.h>
using namespace std;
// USING PRIORITY QUEUE
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, S});

    vector<int> minDist(V, INT_MAX);
    minDist[S] = 0;

    while (!pq.empty())
    {
        pair<int, int> curr = pq.top();
        int node = curr.second, dist = curr.first;
        pq.pop();

        for (auto &neighbor : adj[node])
        {
            int newDist = neighbor[1] + dist;
            if (minDist[neighbor[0]] > newDist)
            {
                minDist[neighbor[0]] = newDist;
                pq.push({newDist, neighbor[0]});
            }
        }
    }
    return minDist;
}
int main(void) {
    
    return 0;
}