// https://leetcode.com/problems/surrounded-regions/description/

public class SurroundedRegions {

    void dfs(char[][] board, boolean[][] newBoard, int i, int j) {
        if (i < 0 || j < 0 || i >= board.length || j >= board[0].length || board[i][j] == 'X' || newBoard[i][j]) {
            return;
        }
        newBoard[i][j] = true;
        dfs(board, newBoard, i + 1, j);
        dfs(board, newBoard, i - 1, j);
        dfs(board, newBoard, i, j + 1);
        dfs(board, newBoard, i, j - 1);
    }

    public void solve(char[][] board) {
        boolean[][] newBoard = new boolean[board.length][board[0].length];
        // left and right
        for (int i = 0; i < board.length; i++) {
            dfs(board, newBoard, i, 0);
            dfs(board, newBoard, i, board[0].length - 1);
        }
        // up and down
        for (int j = 0; j < board[0].length; j++) {
            dfs(board, newBoard, 0, j);
            dfs(board, newBoard, board.length - 1, j);
        }

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (!newBoard[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
}