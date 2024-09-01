// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
#include<bits/stdc++.h>
using namespace std;
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    queue<int> q;
    vector<int> visited(V, 0);
    vector<int> bfs;
    q.push(0);
    visited[0] = 1;
    while(!q.empty()) {
        int curr = q.front();
        bfs.push_back(curr);
        q.pop();
        for(auto neighbor: adj[curr]) {
            if(visited[neighbor] == 0) {
                q.push(neighbor);
                visited[neighbor] = 1;
            }
        }
    }
    return bfs;
}
int main(void) {
    
    return 0;
}