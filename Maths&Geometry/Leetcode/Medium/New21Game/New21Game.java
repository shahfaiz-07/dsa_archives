// https://leetcode.com/problems/new-21-game/

public class New21Game {
    public double new21Game(int n, int k, int maxPts) {
        double[] P = new double[n + 1];
        P[0] = 1;
        double probSum = (k == 0) ? 0 : 1;
        for(int i=1; i<=n; i++) {
            P[i] = probSum/maxPts;
            if(i < k) {
                probSum += P[i];
            }
            if(i - maxPts >= 0 && i - maxPts < k)
                probSum -= P[i-maxPts];
        }
        double res = 0.0;
        for(int i=k; i<=n; i++) {
            res += P[i];
        }
        return res;
    }
}
