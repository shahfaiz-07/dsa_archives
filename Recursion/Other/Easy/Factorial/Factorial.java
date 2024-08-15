public class Factorial {
    static long factorial(int n, long product) {
        if(n <= 1) {
            return product;
        }
        return factorial(n-1, product*n); // using tail recursion
    }
    public static void main(String[] args) {
        System.out.println(factorial(20, 1));
    }
}