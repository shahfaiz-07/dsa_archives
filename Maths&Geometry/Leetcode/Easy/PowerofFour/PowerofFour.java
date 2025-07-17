public class PowerofFour {

    // M1 - divide consecutively by 4

    // M2 - log(n) should be integer

    public boolean isPowerOfFour(int n) {
        if(n <= 0) return false;
        // log_4 n should be an integer
        double x = Math.log(n)/Math.log(4);

        return (int)x == x;
    }

    // M3 - Property : 1. n is Power of 2, 2. n-1 is divisible by 3

    public boolean isPowerOfFour(int n) {
        if(n <= 0) return false;
        // power of 2
        if((n & (n - 1)) != 0) return false;
        // n - 1 divisible by 3
        return (n - 1)%3 == 0;
    }
}