// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
#include<bits/stdc++.h>
using namespace std;
// Using Floyd Warshall
int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    // creating adj matrix
    vector<vector<int>> adj(n, vector<int>(n, 1e4 + 1));
    for (vector<int> &edge : edges)
    {
        adj[edge[0]][edge[1]] = edge[2];
        adj[edge[1]][edge[0]] = edge[2];
    }

    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == via || j == via || i == j)
                    continue;
                long viaDist = adj[i][via] + adj[via][j];
                if (viaDist < adj[i][j])
                {
                    adj[i][j] = viaDist;
                }
            }
        }
    }

    int lastMinCities = INT_MAX, lastCityWithMin = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] <= distanceThreshold)
            {
                count++;
            }
        }
        if (count <= lastMinCities)
        {
            lastMinCities = count;
            lastCityWithMin = i;
        }
    }
    return lastCityWithMin;
}
// Using Dijkstra
int dijkstra(int n, vector<vector<pair<int, int>>> &adj, int threshold, int src)
{
    vector<int> minDist(n, INT_MAX);
    minDist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> st;
    st.push(make_pair(0, src));

    while (!st.empty())
    {
        pair<int, int> curr = st.top();
        int node = curr.second, dist = curr.first;
        st.pop();
        for (pair<int, int> &neighbor : adj[node])
        {
            int newDist = neighbor.second + dist;
            if (minDist[neighbor.first] > newDist)
            {
                minDist[neighbor.first] = newDist;
                st.push(make_pair(newDist, neighbor.first));
            }
        }
    }
    int count = 0;
    for (int dist : minDist)
    {
        if (dist <= threshold)
            count++;
    }
    return count;
}
int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    // creating adj list
    vector<vector<pair<int, int>>> adj(n);
    for (vector<int> &edge : edges)
    {
        adj[edge[0]].emplace_back(make_pair(edge[1], edge[2]));
        adj[edge[1]].emplace_back(make_pair(edge[0], edge[2]));
    }
    int lastMinCities = INT_MAX, lastCity = -1;
    for (int i = 0; i < n; i++)
    {
        int count = dijkstra(n, adj, distanceThreshold, i);
        if (count <= lastMinCities)
        {
            lastMinCities = count;
            lastCity = i;
        }
    }
    return lastCity;
}
int main(void) {
    
    return 0;
}