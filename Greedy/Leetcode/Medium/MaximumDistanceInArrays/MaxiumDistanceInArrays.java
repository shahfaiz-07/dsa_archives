// https://leetcode.com/problems/maximum-distance-in-arrays/
import java.util.List;

public class MaxiumDistanceInArrays {
    public int maxDistance(List<List<Integer>> arrays) {
        int up_max = arrays.get(0).get(arrays.get(0).size() - 1), low_min = arrays.get(0).get(0), diff = 0;

        for(int i=1; i<arrays.size(); i++) {
            diff =Math.max(diff, Math.abs(up_max -arrays.get(i).get(0)));
            diff =Math.max(diff,  Math.abs(low_min- arrays.get(i).get(arrays.get(i).size() - 1)));
            up_max =Math.max(up_max , arrays.get(i).get(arrays.get(i).size() - 1));
            low_min = Math.min(low_min, arrays.get(i).get(0));
        }
        return diff;
    }
    public static void main(String[] args) {
        
    }
}
