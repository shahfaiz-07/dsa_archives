// https://leetcode.com/problems/pacific-atlantic-water-flow/

#include<bits/stdc++.h>
using namespace std;

void dfsPacific(vector<vector<int>> &heights, vector<vector<int>> &visited, int i, int j, int prevHeight)
{
    if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || visited[i][j] || heights[i][j] < prevHeight)
    {
        return;
    }
    visited[i][j] = 1;
    dfsPacific(heights, visited, i + 1, j, heights[i][j]);
    dfsPacific(heights, visited, i - 1, j, heights[i][j]);
    dfsPacific(heights, visited, i, j + 1, heights[i][j]);
    dfsPacific(heights, visited, i, j - 1, heights[i][j]);
}

void dfsAtlantic(vector<vector<int>> &heights, vector<vector<int>> &visited, int i, int j, int prevHeight, vector<vector<int>> &ans)
{
    if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || visited[i][j] == 2 || heights[i][j] < prevHeight)
    {
        return;
    }
    if (visited[i][j] == 1)
    {
        ans.push_back({i, j});
    }

    visited[i][j] = 2;
    dfsAtlantic(heights, visited, i + 1, j, heights[i][j], ans);
    dfsAtlantic(heights, visited, i - 1, j, heights[i][j], ans);
    dfsAtlantic(heights, visited, i, j + 1, heights[i][j], ans);
    dfsAtlantic(heights, visited, i, j - 1, heights[i][j], ans);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    vector<vector<int>> visited(heights.size(), vector<int>(heights[0].size(), 0));
    vector<vector<int>> ans;
    // try to visit from pacific ocean i = 0, j = 0
    for (int i = 0; i < heights.size(); i++)
    {
        dfsPacific(heights, visited, i, 0, INT_MIN);
    }
    for (int j = 0; j < heights[0].size(); j++)
    {
        dfsPacific(heights, visited, 0, j, INT_MIN);
    }

    // now visit from atlantic ocean and add to answer
    for (int i = 0; i < heights.size(); i++)
    {
        dfsAtlantic(heights, visited, i, heights[0].size() - 1, INT_MIN, ans);
    }

    for (int j = 0; j < heights[0].size(); j++)
    {
        dfsAtlantic(heights, visited, heights.size() - 1, j, INT_MIN, ans);
    }
    return ans;
}