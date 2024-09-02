// https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1
public class BitManipulation {
    static void bitManipulation(int num, int i) {
        // code here
        System.out.println((((num >> (i - 1)) & 1) == 1 ? 1 : 0) + " " + (num | (1 << (i - 1))) + " " + (num & ~(1 << (i - 1))));
    }
    public static void main(String[] args) {
        bitManipulation(678883006, 16);
    }
}
