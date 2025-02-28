// https://leetcode.com/problems/surrounded-regions/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &board, vector<vector<bool>> &newBoard, int i, int j)
{
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || newBoard[i][j] || board[i][j] == 'X')
    {
        return;
    }
    newBoard[i][j] = true;
    dfs(board, newBoard, i + 1, j);
    dfs(board, newBoard, i - 1, j);
    dfs(board, newBoard, i, j + 1);
    dfs(board, newBoard, i, j - 1);
}

void solve(vector<vector<char>> &board)
{
    vector<vector<bool>> newBoard(board.size(), vector<bool>(board[0].size(), false));

    // left and right
    for (int i = 0; i < board.size(); i++)
    {
        dfs(board, newBoard, i, 0);
        dfs(board, newBoard, i, board[0].size() - 1);
    }
    // up and down
    for (int j = 0; j < board[0].size(); j++)
    {
        dfs(board, newBoard, 0, j);
        dfs(board, newBoard, board.size() - 1, j);
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (!newBoard[i][j])
            {
                board[i][j] = 'X';
            }
        }
    }
}