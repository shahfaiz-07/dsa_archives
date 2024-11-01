// https://leetcode.com/problems/n-queens/
#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<string> &board, int i, int j)
{
    int x = i, y = j - 1; // left
    while (y >= 0)
    {
        if (board[x][y] == 'Q')
        {
            return false;
        }
        y--;
    }

    x = i - 1, y = j - 1; // up-left
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 'Q')
        {
            return false;
        }
        x--;
        y--;
    }

    x = i + 1, y = j - 1; // down-left
    while (x < board.size() && y >= 0)
    {
        if (board[x][y] == 'Q')
        {
            return false;
        }
        x++;
        y--;
    }
    return true;
}
void put(int index, int n, vector<string> &board, vector<vector<string>> &ans)
{
    if (index == n)
    {
        ans.emplace_back(board);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, index))
        {
            board[i][index] = 'Q';
            put(index + 1, n, board, ans);
            board[i][index] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    string s(n, '.');
    vector<string> board;
    for (int i = 0; i < n; i++)
    {
        board.emplace_back(s);
    }
    put(0, n, board, ans);
    return ans;
}
int main(void) {
    
    return 0;
}