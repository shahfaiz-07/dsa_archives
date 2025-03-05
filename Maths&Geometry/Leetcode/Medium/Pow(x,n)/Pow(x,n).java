// https://leetcode.com/problems/powx-n/

import java.util.*;
public class Pow {
    Map<Long, Double> hash = new HashMap<>();

    double power(double x, long n) {
        if (n == 0) {
            return 1;
        } else {
            double ans = hash.getOrDefault(n, 0.0);
            if (ans != 0.0) {
                return ans;
            }
            if (n % 2 == 0) {
                ans = power(x * x, n / 2);
            } else {
                ans = x * power(x, n - 1);
            }
            hash.put(n, ans);
            return ans;
        }
    }

    public double myPow(double x, int n) {
        long nn = n;
        if (n < 0) {
            return 1 / power(x, -nn);
        } else {
            return power(x, nn);
        }
    }
}
