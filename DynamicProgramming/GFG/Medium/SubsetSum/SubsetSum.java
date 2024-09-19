// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
import java.util.Arrays;

public class SubsetSum {
    // TABULATION
    static Boolean isSubsetSum(int N, int arr[], int sum) {
        // code here
        boolean dp[][] = new boolean[N][sum + 1];
        for (int i = 0; i < N; i++) {
            dp[i][0] = true;
        }
        if (arr[0] <= sum) {
            dp[0][arr[0]] = true; // if index 0 is equal to target sum

                }for (int i = 1; i < N; i++) {
            for (int s = 1; s <= sum; s++) {
                boolean pick = false;
                if (s - arr[i] >= 0) {
                    pick = dp[i - 1][s - arr[i]];
                }
                boolean notPick = dp[i - 1][s];
                dp[i][s] = pick || notPick;
            }
        }
        return dp[N - 1][sum];
    }
    // MEMOIZATION
    static boolean exists(int arr[], int sum, int index, int dp[][]) {
        if (sum == 0) {
            return true;
        }
        if (sum < 0 || index < 0) {
            return false;
        }
        if (dp[index][sum] != -1) {
            return dp[index][sum] == 1;
        }
        if (exists(arr, sum - arr[index], index - 1, dp) || exists(arr, sum, index - 1, dp)) {
            dp[index][sum] = 1;
            return true;
        }
        dp[index][sum] = 0;
        return false;
    }

    static Boolean isSubsetSum2(int N, int arr[], int sum) {
        // code here
        int dp[][] = new int[N][sum + 1];
        for (int i = 0; i < N; i++) {
            Arrays.fill(dp[i], -1);
        }
        return exists(arr, sum, N - 1, dp);
    }
}
