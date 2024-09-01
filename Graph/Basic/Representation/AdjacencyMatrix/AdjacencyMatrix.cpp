#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> printGraph(int V, vector<pair<int, int>> &edges) {
    vector<vector<int>> graph(V, vector<int>(V, 0));
    for(auto edge: edges) {
        graph[edge.first][edge.second] = 1;
        graph[edge.second][edge.first] = 1;
    }
    return graph;
}
int main(void) {
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(4, 1));
    edges.push_back(make_pair(4, 3));
    edges.push_back(make_pair(1, 3));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(3, 2));
    vector<vector<int>> graph = printGraph(5, edges);
    for(auto v: graph) {
        for(int i: v) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}