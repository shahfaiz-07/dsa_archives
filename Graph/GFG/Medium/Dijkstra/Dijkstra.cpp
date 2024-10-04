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
//USING SET
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    set<pair<int, int>> st;
    vector<int> dist(V, INT_MAX);

    dist[S] = 0;

    st.emplace(make_pair(0, S));

    while (!st.empty())
    {
        auto curr = *(st.begin());
        int node = curr.second;
        int distance = curr.first;

        st.erase(curr);

        for (auto neighbor : adj[node])
        {
            int newDist = neighbor[1] + distance;

            if (dist[neighbor[0]] > newDist)
            {
                if (dist[neighbor[0]] != INT_MAX)
                {
                    st.erase(make_pair(dist[neighbor[0]], neighbor[0]));
                }
                dist[neighbor[0]] = newDist;
                st.emplace(make_pair(newDist, neighbor[0]));
            }
        }
    }
    return dist;
}
int main(void) {
    
    return 0;
}