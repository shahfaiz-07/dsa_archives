// https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/

public class DetermineifaCellIsReachableataGivenTime {
    public boolean isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy) {
            return t != 1;
        }
        int dx = Math.abs(sx - fx);
        int dy = Math.abs(sy - fy);
        return t >= Math.max(dx, dy);
    }
}
