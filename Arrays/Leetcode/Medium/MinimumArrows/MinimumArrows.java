// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

import java.util.Arrays;

public class MinimumArrows {
    // concept of overlapping after sort (intervals)
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (int[]a, int[]b) -> {
            return Integer.compare(a[0],b[0]);
        });

        int i = 1, count = 0;
        int[] last_point = points[0];
        while (i < points.length) {
            int ce = points[i][1], cs = points[i][0], le = last_point[1];
            if (le < cs) {
                // require different arrows
                last_point = points[i];
                i++;
            } else if (le <= ce) {
                i++;
                count++;
            } else {
                last_point = points[i];
                i++;
                count++;
            }
        }
        return points.length - count;
    }
}
