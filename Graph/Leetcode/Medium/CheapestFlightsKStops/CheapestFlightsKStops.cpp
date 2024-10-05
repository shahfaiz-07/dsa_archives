// https://leetcode.com/problems/cheapest-flights-within-k-stops/
#include<bits/stdc++.h>
using namespace std;
class Tuple
{
public:
    int price, k, node;
    Tuple(int d, int k1, int n) : price(d), k(k1), node(n) {}

    bool operator<(const Tuple other) const
    {
        return price < other.price;
    }
};
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto edge : flights)
    {
        adj[edge[0]].emplace_back(make_pair(edge[1], edge[2]));
    }
    vector<int> minPrice(n, INT_MAX);
    minPrice[src] = 0;

    queue<Tuple> q;
    q.push(Tuple(0, 0, src));

    while (!q.empty())
    {
        auto curr = q.front();
        int stops = curr.k, price = curr.price, node = curr.node;
        q.pop();
        for (auto neighbor : adj[node])
        {
            if (stops == k && neighbor.first != dst)
                continue;
            int newPrice = neighbor.second + price;
            if (newPrice < minPrice[neighbor.first])
            {
                minPrice[neighbor.first] = newPrice;
                q.emplace(Tuple(newPrice, stops + 1, neighbor.first));
            }
        }
    }

    return minPrice[dst] == INT_MAX ? -1 : minPrice[dst];
}
int main(void) {
    
    return 0;
}