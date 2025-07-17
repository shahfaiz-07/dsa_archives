// https://leetcode.com/problems/minimum-time-visiting-all-points/
public class MinimumTimeVisitingAllPoints {

    public int minTimeToVisitAllPoints(int[][] points) {
        int t = 0;
        for(int i=1; i<points.length; i++) {
            int dx = Math.abs(points[i][0] - points[i-1][0]);
            int dy = Math.abs(points[i][1] - points[i-1][1]);
            t += Math.max(dx, dy);
        }
        return t;
    }
}