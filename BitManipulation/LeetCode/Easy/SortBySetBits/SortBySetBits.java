// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

import java.util.Arrays;

public class SortBySetBits {
    public int[] sortByBits(int[] arr) {
        Integer[] boxedArr = new Integer[arr.length];
        for (int i = 0; i < arr.length; i++) {
            boxedArr[i] = arr[i];
        }
        Arrays.sort(boxedArr, (a, b) -> {
            int cA = Integer.bitCount(a);
            int cB = Integer.bitCount(b);
            if(cA == cB) return a.compareTo(b);
            return Integer.compare(cA, cB);
        });
        for (int i = 0; i < arr.length; i++) {
            arr[i] = boxedArr[i];
        }

        return arr;
    }
}
