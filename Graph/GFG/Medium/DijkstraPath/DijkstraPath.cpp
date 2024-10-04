// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    // Code here
    set<pair<int, int>> st;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (vector<int> &edge : edges)
    {
        adj[edge[0]].emplace_back(make_pair(edge[1], edge[2]));
        adj[edge[1]].emplace_back(make_pair(edge[0], edge[2]));
    }
    vector<pair<int, int>> minDist(n + 1, make_pair(-1, INT_MAX));
    // previous node along with minimum distance
    minDist[1] = make_pair(-1, 0);
    st.emplace(make_pair(0, 1)); // distance and node

    while (!st.empty())
    {
        pair<int, int> curr = *(st.begin());
        int node = curr.second, dist = curr.first;
        st.erase(curr);

        for (pair<int, int> &neighbor : adj[node])
        {
            int newDist = neighbor.second + dist;

            if (minDist[neighbor.first].second > newDist)
            {
                if (minDist[neighbor.first].second != INT_MAX)
                {
                    st.erase(make_pair(minDist[neighbor.first].second, neighbor.first));
                }
                minDist[neighbor.first] = make_pair(node, newDist);
                st.emplace(make_pair(newDist, neighbor.first));
            }
        }
    }
    if (minDist[n].second == INT_MAX)
        return {-1};
    vector<int> path = {minDist[n].second};
    int node = n;
    while (node != -1)
    {
        path.emplace_back(node);
        node = minDist[node].first;
    }
    if (path.back() != 1)
        return {-1};
    int l = 1, r = path.size() - 1;
    while (l < r)
    {
        swap(path[l], path[r]);
        l++;
        r--;
    }
    return path;
}
int main(void) {
    
    return 0;
}