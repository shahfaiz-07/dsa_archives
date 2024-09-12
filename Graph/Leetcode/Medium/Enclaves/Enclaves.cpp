// https://leetcode.com/problems/number-of-enclaves/
#include<bits/stdc++.h>
using namespace std;
int numEnclaves(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> bound;
    for (int i = 0; i < n; i++)
    {
        if (grid[0][i])
        {
            bound.push({0, i});
            visited[0][i] = true;
        }
        if (grid[m - 1][i])
        {
            bound.push({m - 1, i});
            visited[m - 1][i] = true;
        }
    }
    for (int i = 1; i < m - 1; i++)
    {
        if (grid[i][0])
        {
            bound.push({i, 0});
            visited[i][0] = true;
        }
        if (grid[i][n - 1])
        {
            bound.push({i, n - 1});
            visited[i][n - 1] = true;
        }
    }
    vector<pair<int, int>> dels = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!bound.empty())
    {
        int x = bound.front().first, y = bound.front().second;
        bound.pop();
        for (auto del : dels)
        {
            int i = x + del.first, j = y + del.second;
            if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1 && !visited[i][j])
            {
                bound.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] && !visited[i][j])
                count++;
        }
    }

    return count;
}
int main(void) {
    
    return 0;
}