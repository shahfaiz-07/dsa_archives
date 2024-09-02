// https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1
public class KthBitIsSet {
    static boolean checkKthBit(int n, int k) {
        // Your code here
        return (((n >> k) & 1) == 1);
    }
    public static void main(String[] args) {
        System.out.println(checkKthBit(5, 2));
    }
}
