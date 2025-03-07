// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

public class MinDaysToMakeMBouquets {
    public int minDays(int[] bloomDay, int m, int k) {
        int val = -1;
        for (int ele : bloomDay) {
            if (ele > val) {
                val = ele;
            }
        }
        int l = 0, r = val;
        int ans = -1;
        while (l <= r) {
            int mid = r - (r - l) / 2;
            int c = 0, flowers = 0;
            boolean found = false;
            for (int i = 0; i < bloomDay.length; i++) {
                if (bloomDay[i] <= mid) {
                    c++;
                    if (c == k) {
                        flowers++;
                        if (flowers == m) {
                            found = true;
                            break;
                        }
                        c = 0;
                    }
                } else {
                    c = 0;
                }
            }
            if (found) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
}
