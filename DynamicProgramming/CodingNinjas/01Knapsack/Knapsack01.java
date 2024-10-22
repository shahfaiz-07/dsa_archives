// https://www.naukri.com/code360/problems/0-1-knapsack_920542

public class Knapsack01 {
    // MEMOIZATION
    static int getMax(int[] weight, int[] value, int index, int maxWeight, int dp[][]) {
        if (index == -1 || maxWeight == 0) {
            return 0;
        }

        if (dp[index][maxWeight] != 0) {
            return dp[index][maxWeight];
        }

        int pick = Integer.MIN_VALUE;
        if (maxWeight - weight[index] >= 0) {
            pick = getMax(weight, value, index - 1, maxWeight - weight[index], dp) + value[index];
        }
        int notPick = getMax(weight, value, index - 1, maxWeight, dp);

        dp[index][maxWeight] = Math.max(pick, notPick);
        return dp[index][maxWeight];
    }

    static int knapsack1(int[] weight, int[] value, int n, int maxWeight) {

        /* Your class should be named Solution
            * Don't write main().
            * Don't read input, it is passed as function argument.
            * Change in the given tree itself.
            * No need to return or print the output.
            * Taking input and printing output is handled automatically.
         */
        int dp[][] = new int[n][maxWeight + 1];
        return getMax(weight, value, n - 1, maxWeight, dp);
    }

    // TABULATION
    static int knapsack(int[] weight, int[] value, int n, int maxWeight) {

        /* Your class should be named Solution
            * Don't write main().
            * Don't read input, it is passed as function argument.
            * Change in the given tree itself.
            * No need to return or print the output.
            * Taking input and printing output is handled automatically.
         */
        int dp[][] = new int[maxWeight + 1][n];
        for (int i = weight[0]; i <= maxWeight; i++) {
            dp[i][0] = value[0];
        }
        for (int i = 1; i <= maxWeight; i++) {
            for (int j = 1; j <= n - 1; j++) {
                int pick = Integer.MIN_VALUE;
                if (i - weight[j] >= 0) {
                    pick = dp[i - weight[j]][j - 1] + value[j];
                }
                int notPick = dp[i][j - 1];
                dp[i][j] = Math.max(pick, notPick);
            }
        }
        return dp[maxWeight][n - 1];
    }
}
