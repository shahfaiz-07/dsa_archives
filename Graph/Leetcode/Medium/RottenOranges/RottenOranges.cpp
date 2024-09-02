// https://leetcode.com/problems/rotting-oranges/description/
#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>> &grid)
{
    vector<pair<int, int>> diffs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    queue<pair<int, int>> q;
    int c = 0, oneCount = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 2)
            {
                q.push(make_pair(i, j));
            }
            else if (grid[i][j] == 1)
            {
                oneCount++;
            }
        }
    }
    if (q.size() == 0)
    {
        if (oneCount > 0)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    int level = -1;
    while (!q.empty())
    {
        level++;
        int size = q.size();
        for (int i = 1; i <= size; i++)
        {
            pair<int, int> curr = q.front();
            q.pop();
            for (auto diff : diffs)
            {
                int x = curr.first + diff.first, y = curr.second + diff.second;
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1)
                {
                    oneCount--;
                    grid[x][y] = 2;
                    q.push(make_pair(x, y));
                }
            }
        }
    }
    return (oneCount == 0) ? level : -1;
}
int main(void)
{

    return 0;
}