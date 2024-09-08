// http://www.geeksforgeeks.org/problems/introduction-to-dp/1
import java.util.Arrays;

public class IntroductionToDP {
    static final int MOD = (int)(1e9+7);
    private static long f(int n, long dp[]) {
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        dp[n] = (f(n-1, dp) + f(n-2, dp))%MOD;
        return dp[n];
    }
    static long topDown(int n) {
        // code here
        if(n <= 1) {
            return (long)n;
        }
        long dp[] = new long[n+1];
        Arrays.fill(dp, -1);
        return f(n, dp);
    }

    static long bottomUp(int n) {
        // code here
        if(n <= 1) {
            return n;
        }
        
        long a = 1, b = 0, curr = 0;
        for(int i=2; i<=n; i++) {
            curr = (a + b)%MOD;
            b = a;
            a = curr;
        }
        return curr;
    }
    public static void main(String[] args) {
        System.out.println(topDown(1202));
        System.out.println(bottomUp(1202));
    }
}
