// https://www.geeksforgeeks.org/problems/shortest-job-first/1

import java.util.Arrays;

public class SJF {
    static int solve(int bt[] ) {
    // code here
        Arrays.sort(bt);
        int wait = 0, total = 0;
        for(int i=1; i<bt.length; i++) {
            wait = wait + bt[i-1];
            total = total + wait;
        }
        return total/bt.length;
   }
}
