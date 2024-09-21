
import java.util.Arrays;

// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
public class SubsetSumEqualK {
    final int MOD = (int) 1e9 + 7;

    int count(int arr[], int target, int index, int[][] dp) {
        if (index == 0) {
            if (target == 0 && arr[0] == 0) {
                return 2;
            }
            if (target == 0 || target == arr[0]) {
                return 1;
            }
            return 0;
        }
        if (dp[index][target] != -1) {
            return dp[index][target];
        }
        // pick and not pick
        int p = 0;
        if (target >= arr[index]) {
            p = count(arr, target - arr[index], index - 1, dp);
        }
        int nP = count(arr, target, index - 1, dp);
        return dp[index][target] = (p + nP) % MOD;
    }

    public int perfectSum(int arr[], int n, int sum) {
        // Your code goes here
        int dp[][] = new int[n][sum + 1];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
        return count(arr, sum, n - 1, dp);
    } 
}