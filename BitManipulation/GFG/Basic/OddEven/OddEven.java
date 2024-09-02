// https://www.geeksforgeeks.org/problems/odd-or-even3618/1
public class OddEven {
    static String oddEven(int n) {
        // code here
        return ((n & 1) == 0) ? "even" : "odd";
    }
    public static void main(String[] args) {
        System.out.println(oddEven(5));
    }
}
