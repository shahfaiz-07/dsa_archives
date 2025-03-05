// https://leetcode.com/problems/set-matrix-zeroes/

public class SetMatrixZeros {
    public void setZeroes(int[][] matrix) {
        int markerRow = -1, markerCol = -1;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == 0) {
                    if (markerRow == -1) {
                        markerRow = i;
                        markerCol = j;
                    }
                    matrix[markerRow][j] = 0;
                    matrix[i][markerCol] = 0;
                }
            }
        }

        if (markerRow != -1) {
            // use markerRow to set columns as 0
            for (int j = 0; j < matrix[0].length; j++) {
                // do not wipe out the markerColumn
                if (matrix[markerRow][j] == 0 && j != markerCol) {
                    // set that column as 0
                    for (int i = 0; i < matrix.length; i++) {
                        matrix[i][j] = 0;
                    }
                }
            }
            for (int i = 0; i < matrix.length; i++) {
                if (matrix[i][markerCol] == 0) {
                    // set that row as 0
                    for (int j = 0; j < matrix[0].length; j++) {
                        matrix[i][j] = 0;
                    }
                }
            }

            // wipe out markerColumn
            for (int i = 0; i < matrix.length; i++) {
                matrix[i][markerCol] = 0;
            }
        }
    }
}
