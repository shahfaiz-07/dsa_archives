// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &grid, int x, int y, int startX, int startY, vector<vector<bool>> &visited, vector<pair<int, int>> &path, vector<pair<int, int>> &dels)
{
    path.push_back({x - startX, y - startY});
    visited[x][y] = true;
    for (auto del : dels)
    {
        int i = x + del.first, j = y + del.second;
        if (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && !visited[i][j] && grid[i][j] == 1)
        {
            dfs(grid, i, j, startX, startY, visited, path, dels);
        }
    }
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    // code here
    vector<pair<int, int>> dels = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    set<vector<pair<int, int>>> paths;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] && !visited[i][j])
            {
                vector<pair<int, int>> path;
                dfs(grid, i, j, i, j, visited, path, dels);
                paths.emplace(path);
            }
        }
    }
    return paths.size();
}
int main(void) {
    
    return 0;
}