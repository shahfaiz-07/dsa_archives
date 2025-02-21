// https://leetcode.com/problems/valid-sudoku/

#include<bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{

    for (int i = 0; i < 9; i++)
    {
        vector<bool> box(10, false);
        vector<bool> row(10, false);
        vector<bool> col(10, false);
        int rowBase = i / 3, colBase = i % 3;
        for (int j = 0; j < 9; j++)
        {
            int rowOffset = j / 3, colOffset = j % 3;
            char rowEle = board[i][j];
            char colEle = board[j][i];
            char boxEle = board[3 * rowBase + rowOffset][3 * colBase + colOffset];
            if ((rowEle != '.' && row[rowEle - '0']) || (colEle != '.' && col[colEle - '0']) || (boxEle != '.' && box[boxEle - '0']))
            {
                return false;
            }
            if (rowEle != '.')
                row[rowEle - '0'] = true;
            if (colEle != '.')
                col[colEle - '0'] = true;
            if (boxEle != '.')
                box[boxEle - '0'] = true;
        }
    }

    return true;
}