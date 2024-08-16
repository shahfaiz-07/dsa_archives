// https://leetcode.com/problems/word-search/description/
public class WordSearch {
    static boolean traverse(char[][] board, String word, int i, int j, int index, String seq) {
        if (index == word.length()) {
            return true;
        }
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] != word.charAt(index)) {
            return false;
        }
        char x = board[i][j];
        board[i][j] = ' ';
        // right
        boolean r = traverse(board, word, i, j + 1, index + 1, seq + x);
        if (r) {
            return r;
        }
        // down 
        boolean d = traverse(board, word, i + 1, j, index + 1, seq + x);
        if (d) {
            return d;
        }

        // left
        boolean l = traverse(board, word, i, j - 1, index + 1, seq + x);
        if (l) {
            return l;
        }

        // up 
        boolean u = traverse(board, word, i - 1, j, index + 1, seq + x);
        if (u) {
            return u;
        }

        board[i][j] = x;

        return false;
    }

    public static boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == word.charAt(0)) {
                    if (traverse(board, word, i, j, 0, "")) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        char[][] board = {{'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
        System.out.println(exist(board, "SEE"));
    }
}
