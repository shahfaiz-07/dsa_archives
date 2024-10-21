// https://leetcode.com/problems/insert-interval/

import java.util.ArrayList;
import java.util.List;


public class InsertInterval {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> arr = new ArrayList<>();
        int i = 0, n = intervals.length;
        while (i < n && newInterval[0] > intervals[i][1]) {
            arr.add(intervals[i]);
            i++;
        }
        int start = i < n ? Math.min(newInterval[0], intervals[i][0]) : newInterval[0];
        int end = newInterval[1];
        while (i < n && newInterval[1] >= intervals[i][0]) {
            end = Math.max(end, intervals[i][1]);
            i++;
        }
        arr.add(new int[]{start, end});
        while (i < n) {
            arr.add(intervals[i]);
            i++;
        }
        int ans[][] = arr.toArray(new int[arr.size()][]);

        return ans;
    }
}
