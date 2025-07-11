// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
import java.util.*;

public class MatrixChainMultiplication {

    static int recurse(int[] arr, int i, int j, int[][] dp) {
        if(i == j) return 0;
        if(dp[i][j] != 0) return dp[i][j];
        int min = Integer.MAX_VALUE;
        for(int k=i; k<=j-1; k++) {
            int op = arr[i-1] * arr[k] * arr[j] + recurse(arr, i, k, dp) + recurse(arr, k+1, j, dp);
            min = Math.min(min, op);
        }
        dp[i][j] = min;
        return min;
    }
    static int matrixMultiplication(int arr[]) {
        // code here
        // Partition DP :-
        // 1. Start with the entire array
        // 2. Try all partitions(run loop)
        // 3. Return best possible 2 partitions
        // f(i, j) - min multiplications to multiply matrix from i to j
        int[][] dp = new int[arr.length][arr.length];
        return recurse(arr, 1, arr.length-1, dp);
    }
}