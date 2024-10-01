
import java.util.Arrays;

// https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1
public class CeilTheFloor {
    public int[] getFloorAndCeil(int x, int[] arr) {
        // code here
        int ans[] = {-1, -1};
        int l = 0, r = arr.length - 1;
        Arrays.sort(arr);

        while (l <= r) {
            int m = r - (r - l) / 2;
            if (arr[m] == x) {
                return new int[]{x, x};
            }

            if (x > arr[m]) {
                ans[0] = arr[m];
                l = m + 1;
            } else {
                ans[1] = arr[m];
                r = m - 1;
            }
        }
        return ans;
    }
}