// https://www.geeksforgeeks.org/problems/square-root/0

public class SquareRoot {

    long floorSqrt(long n) {
        // Your code here
        long l = 0, u = n;
        long r = -1;
        while (l <= u) {
            long m = u - (u - l) / 2;
            if (m * m == n) {
                return m;
            }
            if (m * m < n) {
                r = m;
                l = m + 1;
            } else {
                u = m - 1;
            }
        }
        return r;
    }
}
