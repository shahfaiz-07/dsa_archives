// https://www.geeksforgeeks.org/problems/rotation4723/1

import java.util.List;

public class FindKthRotation {

    public int findKRotation(List<Integer> arr) {
        // Code here
        int l = 0, r = arr.size() - 1;
        while(l < r) {
            int m = (l + r)/2;
            // go towards the unsorted half
            if(arr.get(m) <= arr.get(r)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
}