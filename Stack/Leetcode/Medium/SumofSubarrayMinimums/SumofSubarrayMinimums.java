// https://leetcode.com/problems/sum-of-subarray-minimums/

import java.util.ArrayDeque;
import java.util.Deque;

public class SumofSubarrayMinimums {

    int[][] getNSEPSE(int[] arr) {
        int n = arr.length;
        Deque<Integer> stNSE = new ArrayDeque<>();
        Deque<Integer> stPSE = new ArrayDeque<>();
        // first row contains NSE
        // second PSE(incl. equals)
        int[][] ans = new int[2][arr.length];
        for (int i = 0; i < n; i++) {
            // NSE
            while (!stNSE.isEmpty() && arr[stNSE.peek()] >= arr[n - i - 1]) {
                stNSE.pop();
            }
            ans[0][n - i - 1] = stNSE.isEmpty() ? n : stNSE.peek();
            stNSE.push(n - i - 1);

            //PSE
            while (!stPSE.isEmpty() && arr[stPSE.peek()] > arr[i]) {
                stPSE.pop();
            }
            ans[1][i] = stPSE.isEmpty() ? -1 : stPSE.peek();
            stPSE.push(i);
        }
        return ans;
    }

    public int sumSubarrayMins(int[] arr) {
        final int MOD = (int) (1e9 + 7);
        int[][] nsePSE = getNSEPSE(arr);
        long ans = 0;
        for (int i = 0; i < arr.length; i++) {
            ans = (ans + ((long) arr[i] * (nsePSE[0][i] - i) % MOD) * (i - nsePSE[1][i]) % MOD) % MOD;

        }
        return (int) (ans % MOD);
    }
}