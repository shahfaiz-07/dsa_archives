// https://leetcode.com/problems/sudoku-solver

public class SudokuSolver {

    boolean isSafe(char[][] board, char num, int x, int y) {
        for (int i = 0; i < board.length; i++) {
            // row, col
            if (board[x][i] == num || board[i][y] == num) {
                return false;
            }
        }
        // 3x3
        int startX = x - x % 3, startY = y - y % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startX + i][startY + j] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    boolean solve(char[][] board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isSafe(board, num, i, j)) {
                            board[i][j] = num;
                            if (solve(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    public void solveSudoku(char[][] board) {
        solve(board);
    }
}