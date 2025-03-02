// https://neetcode.io/problems/islands-and-treasure
// https://leetcode.com/problems/walls-and-gates/description/
#include<bits/stdc++.h>
using namespace std;
void islandsAndTreasure(vector<vector<int>> &grid)
{
    queue<pair<int, int>> que;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (!grid[i][j])
                que.push({i, j});
        }
    }

    vector<pair<int, int>> dels = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int level = 1;
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            pair<int, int> &curr = que.front();
            que.pop();
            for (pair<int, int> &del : dels)
            {
                int x = curr.first + del.first, y = curr.second + del.second;
                if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == INT_MAX)
                {
                    grid[x][y] = level;
                    que.push({x, y});
                }
            }
        }
        level++;
    }
}