// https://leetcode.com/problems/path-with-minimum-effort/
#include<bits/stdc++.h>
using namespace std;
int minimumEffortPath(vector<vector<int>> &heights)
{
    int m = heights.size(), n = heights[0].size();
    if (m == 1 && n == 1)
        return 0;
    vector<vector<int>> maxHeight(m, vector<int>(n, INT_MAX));
    maxHeight[0][0] = heights[0][0];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push(make_pair(0, make_pair(0, 0)));
    vector<pair<int, int>> dels = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    while (!pq.empty())
    {
        auto curr = pq.top();
        int x = curr.second.first, y = curr.second.second, dist = curr.first;
        if (x == m - 1 && y == n - 1)
            return dist;
        pq.pop();
        // up, down, left and right
        for (pair<int, int> del : dels)
        {
            int nx = x + del.first, ny = y + del.second;

            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                int newDist = max(dist, abs(heights[nx][ny] - heights[x][y]));
                if (maxHeight[nx][ny] > newDist)
                {
                    maxHeight[nx][ny] = newDist;
                    pq.push(make_pair(newDist, make_pair(nx, ny)));
                }
            }
        }
    }

    return 0;
}
int main(void) {
    
    return 0;
}