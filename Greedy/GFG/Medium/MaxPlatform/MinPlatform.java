// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

import java.util.Arrays;

public class MinPlatform {
    static int findPlatform(int arr[], int dep[]) {
        // add your code here
        Arrays.sort(arr);
        Arrays.sort(dep);
        int count = 0, maxCount = 0;
        int r1 = 0, r2 = 0;
        while(r1 < arr.length && r2 < arr.length) {
            if(dep[r2] < arr[r1]) {
                count--;
                r2++;
            } else {
                count++;
                maxCount = Math.max(maxCount, count);
                r1++;
            }
        }
        return maxCount;
    }
}
