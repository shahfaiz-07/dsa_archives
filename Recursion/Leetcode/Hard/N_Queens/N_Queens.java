// https://leetcode.com/problems/n-queens/
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class N_Queens {
    boolean isSafe(char[][] board, int i, int j) {
        int x = i, y = j - 1; // left
        while (y >= 0) {
            if (board[x][y] == 'Q') {
                return false;
            }
            y--;
        }

        x = i - 1;
        y = j - 1; // up-left
        while (x >= 0 && y >= 0) {
            if (board[x][y] == 'Q') {
                return false;
            }
            x--;
            y--;
        }

        x = i + 1;
        y = j - 1; // down-left
        while (x < board.length && y >= 0) {
            if (board[x][y] == 'Q') {
                return false;
            }
            x++;
            y--;
        }
        return true;
    }

    void put(int n, int ind, char[][] board, List<List<String>> ans) {
        if (ind == n) {
            List<String> temp = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                String str = new String(board[i]);
                temp.add(str);
            }
            ans.add(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isSafe(board, i, ind)) {
                board[i][ind] = 'Q';
                put(n, ind + 1, board, ans);
                board[i][ind] = '.';
            }
        }
    }

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();
        char[][] board = new char[n][n];
        for (int i = 0; i < board.length; i++) {
            Arrays.fill(board[i], '.');
        }
        put(n, 0, board, ans);
        return ans;
    }
}