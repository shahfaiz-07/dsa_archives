// https://leetcode.com/problems/valid-sudoku/

public class ValidSudoku {
    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < 9; i++) {
            boolean[] row = new boolean[10];
            boolean[] col = new boolean[10];
            boolean[] box = new boolean[10];
            int rowB = i / 3, colB = i % 3;
            for (int j = 0; j < 9; j++) {
                int rowOff = j / 3, colOff = j % 3;
                char rowEle = board[i][j];
                char colEle = board[j][i];
                char boxEle = board[3 * rowB + rowOff][3 * colB + colOff];

                if (rowEle != '.') {
                    if (row[rowEle - '0']) {
                        return false;
                    }
                    row[rowEle - '0'] = true;
                }
                if (colEle != '.') {
                    if (col[colEle - '0']) {
                        return false;
                    }
                    col[colEle - '0'] = true;
                }
                if (boxEle != '.') {
                    if (box[boxEle - '0']) {
                        return false;
                    }
                    box[boxEle - '0'] = true;
                }
            }
        }
        return true;
    }
}
