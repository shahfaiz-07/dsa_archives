// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
#include<bits/stdc++.h>
using namespace std;
vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    // Code here
    const int MAGIC_NUM = 1e8;
    vector<int> dist(V, MAGIC_NUM);
    dist[S] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        bool changes = false;

        for (vector<int> &edge : edges)
        {
            int u = edge[0], v = edge[1], wt = edge[2];
            if (dist[u] != MAGIC_NUM && dist[u] + wt < dist[v])
            {
                changes = true;
                dist[v] = dist[u] + wt;
            }
        }
        if (!changes)
            return dist;
    }
    // detecting -ve cycle
    for (vector<int> &edge : edges)
    {
        int u = edge[0], v = edge[1], wt = edge[2];
        if (dist[u] != MAGIC_NUM && dist[u] + wt < dist[v])
        {
            return {-1};
        }
    }
    return dist;
}
int main(void) {
    
    return 0;
}