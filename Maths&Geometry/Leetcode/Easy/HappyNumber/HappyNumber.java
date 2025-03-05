// https://leetcode.com/problems/happy-number

public class HappyNumber {
    public boolean isHappy(int n) {
        while (n >= 10) {
            int sum = 0;
            while (n != 0) {
                int d = n % 10;
                sum = sum + d * d;
                n /= 10;
            }
            n = sum;
        }
        return n == 1 || n == 7;
    }
}
