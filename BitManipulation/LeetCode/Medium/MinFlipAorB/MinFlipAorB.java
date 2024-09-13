// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
public class MinFlipAorB {
    public int minFlips(int a, int b, int c) {
        int count = 0;
        while (a != 0 && b != 0 && c != 0) {
            if ((c & 1) == 1) {
                if (((b & 1) == 0) && ((a & 1) == 0)) {
                    count++;
                }
            } else {
                count += ((b & 1) + (a & 1));
            }
            c = c >> 1;
            b = b >> 1;
            a = a >> 1;
        }
        // b became 0, a and c remains
        while (a != 0 && c != 0) {
            if (((a & 1) ^ (c & 1)) == 1) {
                count++;
            }
            a = a >> 1;
            c = c >> 1;
        }
        // a became 0, b and c remains
        while (b != 0 && c != 0) {
            if (((b & 1) ^ (c & 1)) == 1) {
                count++;
            }
            b = b >> 1;
            c = c >> 1;
        }
        // c became 0 a and/or b remains - turn of all remaining bits
        while (a != 0) {
            a = (a & (a - 1));
            count++;
        }
        while (b != 0) {
            b = (b & (b - 1));
            count++;
        }
        // a and b became 0 c remains
        while (c != 0) {
            c = (c & (c - 1));
            count++;
        }
        return count;
    }
}
