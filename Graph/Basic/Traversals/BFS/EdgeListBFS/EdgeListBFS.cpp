// CONSIDERING TRAVERSAL FOR NON CONNECTED COMPONENTS ALSO
#include <bits/stdc++.h>
using namespace std;
void traverse(int start, vector<pair<int, int>> &edges, vector<int> &visited) // main logic
{
    queue<int> open;
    cout << start << " ";
    open.push(start);
    visited[start] = 1;
    while (!open.empty())
    {
        int curr = open.front();
        open.pop();
        for (pair<int, int> edge : edges)
        {
            if (edge.first == curr && visited[edge.second] == 0)
            {
                cout << edge.second << " ";
                visited[edge.second] = 1;
                open.push(edge.second);
            }
            if(edge.second == curr && visited[edge.first] == 0) {
                cout << edge.first << " ";
                visited[edge.first] = 1;
                open.push(edge.first);
            }
        }
    }
    cout << "\n";
}
int traversal(int V, vector<pair<int, int>> &edges)
{
    int count = 0; // number of unconnected components
    vector<int> visited(V, 0);
    for (int i = 1; i < V; i++)
    {
        if(visited[i] == 0) {
            count++;
            traverse(i, edges, visited);
        }
    }
    return count;
}
int main(void)
{
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(2, 1));
    edges.push_back(make_pair(2, 4));
    edges.push_back(make_pair(4, 3));
    edges.push_back(make_pair(1, 3));
    edges.push_back(make_pair(5, 6));
    edges.push_back(make_pair(6, 7));
    edges.push_back(make_pair(5, 7));
    edges.push_back(make_pair(8, 9));
    cout << traversal(11, edges);
    return 0;
}