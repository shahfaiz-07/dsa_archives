// https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

public class PainterPartition {
    boolean canPartition(int[] arr, int k, int m) {
        int time = 0, painters = 1;
        for (int ele : arr) {
            if (time + ele > m) {
                painters++;
                if (painters > k) {
                    return false;
                }
                time = ele;
            } else {
                time += ele;
            }
        }
        return true;
    }

    public int minTime(int[] arr, int k) {
        // code here
        int l = 0, r = 0;
        for (int ele : arr) {
            l = Math.max(l, ele);
            r += ele;
        }
        int ans = r;
        while (l <= r) {
            int m = (r + l) / 2;
            if (canPartition(arr, k, m)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
}
