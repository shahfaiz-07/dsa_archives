// https://leetcode.com/problems/max-points-on-a-line/
import java.util.*;

public class MaxPointsonaLine {
    public int maxPoints(int[][] points) {
        int n = points.length;
        if(n == 1) return 1;
        int ans = 0;
        for(int i=0; i<n; i++) {
            // pick any point and see what angle are other points making with it
            Map<Double, Integer> mp = new HashMap<>(); // angle and count
            for(int j=0; j<n; j++) {
                if(i == j) continue;
                double dy = (points[i][1] - points[j][1]);
                double dx = (points[i][0] - points[j][0]);

                double slope = dx == 0 ? Double.MAX_VALUE : dy/dx;
                int val = mp.compute(slope, (k, v) -> v == null ? 1 : v + 1);
            }
            for(int value: mp.values()) {
                ans = Math.max(ans, value + 1);
            } 
        }
        return ans;
    }
}
