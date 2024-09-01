// https://leetcode.com/problems/number-of-provinces/
#include<bits/stdc++.h>
using namespace std;
void dfs(int start, vector<vector<int>> &isConnected, vector<bool> &visited)
{
    visited[start] = true;
    for (int i = 0; i < isConnected.size(); i++)
    {
        if (isConnected[start][i] == 1 && !visited[i])
        {
            dfs(i, isConnected, visited);
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    vector<bool> visited(isConnected.size(), 0);
    int count = 0;
    for (int i = 0; i < isConnected.size(); i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(i, isConnected, visited);
        }
    }
    return count;
}
int main(void) {
    
    return 0;
}