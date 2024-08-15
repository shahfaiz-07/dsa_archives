import java.util.HashMap;

public class Fibonacci {

    static int nthFibo(int n, HashMap<Integer, Integer> hash) {
        if (n == 0) {
            return 0;
        }
        int x = hash.getOrDefault(n, -1);
        if(x != -1) {
            return x;
        }
        x = nthFibo(n - 1, hash) + nthFibo(n - 2, hash);
        hash.put(n, x);
        return x;
    }

    static int fibonacci(int n) {
        HashMap<Integer, Integer> hash = new HashMap<>();
        hash.put(0, 0);
        hash.put(1, 1);
        return nthFibo(n, hash);
    }

    public static void main(String[] args) {
        System.out.println(fibonacci(15));
    }
}
