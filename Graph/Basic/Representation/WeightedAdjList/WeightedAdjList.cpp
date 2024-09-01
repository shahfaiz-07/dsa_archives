#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> printGraph(int V, vector<vector<int>> &edges) {
    vector<vector<pair<int, int>>> graph(V);
    for(auto edge: edges) {
        graph[edge[0]].push_back(make_pair(edge[1], edge[2]));
        graph[edge[1]].push_back(make_pair(edge[0], edge[2]));
    }
    return graph;
}
int main(void) {
    vector<vector<int>> edges;
    edges.push_back({0, 1, 3});
    edges.push_back({0, 4, 2});
    edges.push_back({4, 1, 5});
    edges.push_back({4, 3, 3});
    edges.push_back({1, 3, 6});
    edges.push_back({1, 2, 3});
    edges.push_back({3, 2, 5});
    vector<vector<pair<int, int>>> graph = printGraph(5, edges);
    for(auto i: graph) {
        for(pair<int, int> j: i) {
            cout << "(" << j.first << ", " << j.second << ") ";
        }
        cout << "\n";
    }
    return 0;
}