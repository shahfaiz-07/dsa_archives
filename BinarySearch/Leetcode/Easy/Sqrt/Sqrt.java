// https://leetcode.com/problems/sqrtx/

public class Sqrt {
    public int mySqrt(int x) {
        if(x == 0) return 0;
        int l = 1, r = x;
        while(l <= r) {
            int m = l + (r - l)/2;
            if(x*1.0/m < m) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
}
