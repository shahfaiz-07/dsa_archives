// https://leetcode.com/problems/01-matrix/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    vector<vector<int>> visited(mat.size(), vector<int>(mat[0].size(), 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == 0)
            {
                q.push(make_pair(make_pair(i, j), 0));
                visited[i][j] = 1;
            }
        }
    }
    vector<pair<int, int>> dels = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    pair<pair<int, int>, int> curr;
    int x, y, dist;
    while (!q.empty())
    {
        curr = q.front();
        x = curr.first.first;
        y = curr.first.second;
        dist = curr.second;
        q.pop();
        for (pair<int, int> del : dels)
        {
            int i = x + del.first, j = y + del.second;
            if (i >= 0 && i < mat.size() && j >= 0 && j < mat[0].size() && visited[i][j] == 0)
            {
                mat[i][j] = dist + 1;
                visited[i][j] = 1;
                q.push(make_pair(make_pair(i, j), mat[i][j]));
            }
        }
    }
    return mat;
}
int main(void) {
    
    return 0;
}