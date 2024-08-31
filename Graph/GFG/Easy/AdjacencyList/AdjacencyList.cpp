// https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges)
{
    vector<vector<int>> graph(V);
    for (auto i : edges)
    {
        graph[i.first].push_back(i.second);
        graph[i.second].push_back(i.first);
    }
    return graph;
}
int main(void)
{
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(4, 1));
    edges.push_back(make_pair(4, 3));
    edges.push_back(make_pair(1, 3));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(3, 2));
    vector<vector<int>> list = printGraph(5, edges);
    for(auto v: list) {
        for(int i: v) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}