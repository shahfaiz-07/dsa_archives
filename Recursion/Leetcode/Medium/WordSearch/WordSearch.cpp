// https://leetcode.com/problems/word-search/description/
#include<bits/stdc++.h>
using namespace std;
bool traverse(vector<vector<char>> &board, string word, int i, int j, int index, string seq)
{
    if (index == word.length())
    {
        return true;
    }
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index])
    {
        return false;
    }
    char x = board[i][j];
    board[i][j] = ' ';
    // right
    bool r = traverse(board, word, i, j + 1, index + 1, seq + x);
    if (r)
    {
        return r;
    }
    // down
    bool d = traverse(board, word, i + 1, j, index + 1, seq + x);
    if (d)
    {
        return d;
    }

    // left
    bool l = traverse(board, word, i, j - 1, index + 1, seq + x);
    if (l)
    {
        return l;
    }

    // up
    bool u = traverse(board, word, i - 1, j, index + 1, seq + x);
    if (u)
    {
        return u;
    }

    board[i][j] = x;

    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == word[0])
            {
                if (traverse(board, word, i, j, 0, ""))
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main(void) {
    vector<vector<char>> board = { {'A', 'B', 'C', 'E'},
                                   { 'S', 'F', 'C', 'S' },
                                   { 'A', 'D', 'E', 'E' } };
    cout << exist(board, "ABCCED");
    return 0;
}