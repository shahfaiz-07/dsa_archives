// https://leetcode.com/problems/shortest-path-in-binary-matrix/
#include<bits/stdc++.h>
using namespace std;
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return -1;

    vector<vector<int>> minDist(n, vector<int>(n, INT_MAX));

    minDist[0][0] = 1;

    queue<pair<int, pair<int, int>>> q;

    q.push(make_pair(1, make_pair(0, 0)));

    while (!q.empty())
    {
        auto curr = q.front();
        int x = curr.second.first, y = curr.second.second, dist = curr.first;
        if (x == n - 1 && y == n - 1)
            return dist;
        q.pop();
        // neighbors will be all of the eight adjacent nodes
        int newDist = dist + 1;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i == 0 && j == 0)
                    continue;

                int nx = x + i, ny = y + j;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] != 1 && minDist[nx][ny] > newDist)
                {
                    minDist[nx][ny] = newDist;
                    q.push(make_pair(newDist, make_pair(nx, ny)));
                }
            }
        }
    }

    return -1;
}
int main(void) {
    
    return 0;
}