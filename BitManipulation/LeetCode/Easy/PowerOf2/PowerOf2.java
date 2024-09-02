// https://leetcode.com/problems/power-of-two/description/
public class PowerOf2 {
    public static boolean isPowerOfTwo(int n) {
        return ((n > 0) && (n & (n - 1)) == 0);
    }
    public static void main(String[] args) {
        System.out.println(isPowerOfTwo(64));
    }
}
