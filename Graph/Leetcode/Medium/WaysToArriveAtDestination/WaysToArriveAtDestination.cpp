// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
#include<bits/stdc++.h>
using namespace std;
int countPaths(int n, vector<vector<int>> &roads)
{
    const int MOD = 1e9 + 7;

    vector<vector<pair<int, int>>> adj(n);

    for (vector<int> &edge : roads)
    {
        adj[edge[0]].emplace_back(make_pair(edge[1], edge[2]));
        adj[edge[1]].emplace_back(make_pair(edge[0], edge[2]));
    }

    vector<long> minCost(n, LONG_MAX);
    minCost[0] = 0;
    vector<long> minWays(n, 0);
    minWays[0] = 1;

    priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;

    pq.push(make_pair(0, 0));

    while (!pq.empty())
    {
        pair<long, long> curr = pq.top();
        long cost = curr.first, node = curr.second;
        long ways = minWays[node];
        pq.pop();
        for (pair<int, int> &neighbor : adj[node])
        {
            long newCost = cost + neighbor.second;

            if (minCost[neighbor.first] > newCost)
            {
                minCost[neighbor.first] = newCost;
                minWays[neighbor.first] = ways;
                pq.push(make_pair(newCost, neighbor.first));
            }
            else if (minCost[neighbor.first] == newCost)
            {
                minWays[neighbor.first] = (minWays[neighbor.first] + ways) % MOD;
            }
        }
    }

    return minWays[n - 1] % MOD;
}
int main(void) {
    
    return 0;
}