// https://www.geeksforgeeks.org/problems/set-bits0143/1

public class CountSetBits {
    static int setBits(int n) {
        // code here
        int c = 0;
        while(n != 0) {
            n = n & (n - 1);
            c++;
        }
        return c;
    }
}
