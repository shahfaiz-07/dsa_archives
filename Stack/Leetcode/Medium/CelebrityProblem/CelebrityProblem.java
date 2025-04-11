// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

public class CelebrityProblem {

    public int celebrity(int mat[][]) {
        // code here
        int n = mat.length;
        int low = 0, high = n - 1;
        while (low < high) {
            if (mat[low][high] == 1) {
                low++;
            } else if (mat[high][low] == 1) {
                high--;
            } else {
                low++;
                high--;
            }
        }
        // check that row and column
        for (int i = 0; i < n; i++) {
            if (low == i) {
                continue;
            }
            if (mat[low][i] == 1 || mat[i][low] == 0) {
                return -1;
            }
        }
        return low;
    }
}