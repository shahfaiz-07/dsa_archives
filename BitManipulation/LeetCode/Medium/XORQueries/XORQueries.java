// https://leetcode.com/problems/xor-queries-of-a-subarray/
public class XORQueries {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int ans[] = new int[queries.length];
        int xors[] = new int[arr.length];
        xors[0] = arr[0];
        for (int i = 1; i < arr.length; i++) {
            xors[i] = arr[i] ^ xors[i - 1];
        }
        for (int i = 0; i < queries.length; i++) {
            int L = queries[i][0];
            int R = queries[i][1];
            ans[i] = xors[R] ^ (L == 0 ? 0 : xors[L - 1]);
        }
        return ans;
    }
}
