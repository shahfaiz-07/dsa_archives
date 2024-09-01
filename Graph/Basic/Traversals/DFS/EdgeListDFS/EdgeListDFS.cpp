#include<bits/stdc++.h>
using namespace std;
// original DFS logic
void DFS(int start, vector<pair<int, int>> &edges, vector<int> &visited, vector<int> &dfs) {
    if(!visited[start]) {
        visited[start] = 1;
        dfs.push_back(start);
        for (auto edge : edges)
        {
            if (edge.first == start && visited[edge.second] == 0)
            {
                DFS(edge.second, edges, visited, dfs);
            }
            else if (edge.second == start && visited[edge.first] == 0)
            {
                DFS(edge.first, edges, visited, dfs);
            }
        }
    }
}
vector<int> traversal(int V, vector<pair<int, int>> &edges) {
    vector<int> visited(V, 0);
    vector<int> dfs;
    for(int i=1; i<V; i++) {
        DFS(i, edges, visited, dfs);
    }
    return dfs;
}
int main(void) {
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(2, 1));
    edges.push_back(make_pair(2, 4));
    edges.push_back(make_pair(4, 3));
    edges.push_back(make_pair(1, 3));
    edges.push_back(make_pair(5, 6));
    edges.push_back(make_pair(6, 7));
    edges.push_back(make_pair(5, 7));
    edges.push_back(make_pair(8, 9));
    vector<int> dfs = traversal(11, edges);
    for(int ele: dfs) {
        cout << ele << " ";
    }
    return 0;
} 