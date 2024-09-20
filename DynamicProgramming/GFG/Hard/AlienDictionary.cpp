// https://www.geeksforgeeks.org/problems/alien-dictionary/1
#include<bits/stdc++.h>
using namespace std;

private:
void topoSort(vector<vector<int>> &adj, int curr, vector<bool> &visited, stack<int> &st)
{
    visited[curr] = true;
    for (int &neighbor : adj[curr])
    {
        if (!visited[neighbor])
        {
            topoSort(adj, neighbor, visited, st);
        }
    }
    st.push(curr);
}

public:
string findOrder(string dict[], int n, int k)
{
    // code here
    vector<vector<int>> adj(k, vector<int>());
    vector<int> inDegree(k, 0);
    for (int i = 0; i < n - 1; i++)
    {
        for (int ind = 0; ind < min(dict[i].length(), dict[i + 1].length()); ind++)
        {
            if (dict[i][ind] != dict[i + 1][ind])
            {
                adj[dict[i][ind] - 'a'].emplace_back(dict[i + 1][ind] - 'a');
                inDegree[dict[i + 1][ind] - 'a']++;
                break;
            }
        }
    }
    stack<int> st;
    vector<bool> visited(k, false);
    for (int i = 0; i < k; i++)
    {
        if (!visited[i])
        {
            topoSort(adj, i, visited, st);
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans += (char)(st.top() + 'a');
        st.pop();
    }
    return ans;
}
int main(void) {
    
    return 0;
}