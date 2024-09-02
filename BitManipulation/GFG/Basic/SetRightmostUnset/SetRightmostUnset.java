// https://www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1
public class SetRightmostUnset {
    static int setBit(int n) {
        // code here
        return (n | n + 1);
    }
    public static void main(String[] args) {
        System.out.println(setBit(11));
    }
}
