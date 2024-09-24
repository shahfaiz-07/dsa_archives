// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
public class NthRoot {
    int findPower(long x, int y) {
        long ans = 1;
        while (y > 0) {
            if ((y & 1) == 1) {
                ans = ans * x;
                if (ans > Integer.MAX_VALUE) {
                    return Integer.MAX_VALUE;
                }
                y = y - 1;
            } else {
                x *= x;
                if (x > Integer.MAX_VALUE) {
                    return Integer.MAX_VALUE;
                }
                y /= 2;
            }
        }
        return (int) ans;
    }

    public int NthRoot(int n, int m) {
        // code here
        int l = 1, u = m;
        while (l <= u) {
            int mid = u - (u - l) / 2;
            int ans = findPower(mid, n);
            if (ans == m) {
                return mid;
            } else if (ans < m) {
                l = mid + 1;
            } else {
                u = mid - 1;
            }
        }
        return -1;
    }
}
