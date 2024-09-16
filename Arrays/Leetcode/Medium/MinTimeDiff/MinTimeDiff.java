// https://leetcode.com/problems/minimum-time-difference/

import java.util.Arrays;
import java.util.List;

public class MinTimeDiff {
    public int findMinDifference(List<String> timePoints) {
        int[] tp = new int[timePoints.size()];
        for(int i=0; i<timePoints.size(); i++) {
            String t1 = timePoints.get(i);
            int hour = Integer.parseInt(t1.substring(0, 2));
            int min = Integer.parseInt(t1.substring(3));
            tp[i] = hour*60 + min;
        }
        Arrays.sort(tp);
        int diff = Math.min(tp[tp.length - 1] - tp[0], (1440 - tp[tp.length - 1]) + tp[0]);
        for(int i=0; i<timePoints.size() - 1; i++) {
            diff = Math.min(diff, (tp[i + 1] - tp[i]));
        }
        return diff;
    }
}
