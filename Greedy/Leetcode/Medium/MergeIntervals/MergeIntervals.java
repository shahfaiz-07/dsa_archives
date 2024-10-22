// https://leetcode.com/problems/merge-intervals/

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class MergeIntervals {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> {
            if (a[0] == b[0]) {
                return a[1] - b[1];
            }
            return a[0] - b[0];
        });
        List<int[]> arr = new ArrayList<>();
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.length; i++) {
            int curStart = intervals[i][0], curEnd = intervals[i][1];
            if (curStart <= end) {
                if (curEnd > end) {
                    end = curEnd;
                }
            } else {
                arr.add(new int[]{start, end});
                start = curStart;
                end = curEnd;
            }
        }
        arr.add(new int[]{start, end});
        return arr.toArray(new int[arr.size()][2]);
    }
}
