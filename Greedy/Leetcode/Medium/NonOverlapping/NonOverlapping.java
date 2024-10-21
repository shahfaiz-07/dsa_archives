// https://leetcode.com/problems/non-overlapping-intervals/

import java.util.Arrays;

public class NonOverlapping {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[1] - b[1]);
        int freeTime = Integer.MIN_VALUE, count = intervals.length;
        for(int[] interval: intervals) {
            int start = interval[0], end = interval[1];
            if(freeTime <= start) {
                freeTime = end;
                count--;
            }
        }
        return count;
    }
}
