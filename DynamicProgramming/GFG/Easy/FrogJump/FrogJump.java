// https://www.geeksforgeeks.org/problems/geek-jump/1
import java.util.Arrays;

public class FrogJump {
    // TABULATION
    public int minimumEnergy(int arr[], int n) {
        //code here
        n = n - 1;
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return Math.abs(arr[1] - arr[0]);
        }
        int prevMin2 = 0, prevMin1 = Math.abs(arr[1] - arr[0]);
        for (int i = 2; i <= n; i++) {
            int j1 = prevMin1 + Math.abs(arr[i] - arr[i - 1]);
            int j2 = prevMin2 + Math.abs(arr[i] - arr[i - 2]);
            prevMin2 = prevMin1;
            prevMin1 = Math.min(j1, j2);
        }
        return prevMin1;
    }
    // MEMOIZATION
    int jump(int height[], int n, int dp[]) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return Math.abs(height[0] - height[1]);
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int jump1 = jump(height, n - 1, dp) + Math.abs(height[n] - height[n - 1]);
        int jump2 = jump(height, n - 2, dp) + Math.abs(height[n] - height[n - 2]);
        dp[n] = Math.min(jump1, jump2);
        return dp[n];
    }

    public int minimumEnergy2(int arr[], int N) {
        //code here
        int dp[] = new int[N];
        Arrays.fill(dp, -1);
        return jump(arr, N - 1, dp);
    }
    public static void main(String[] args) {
        
    }
}
