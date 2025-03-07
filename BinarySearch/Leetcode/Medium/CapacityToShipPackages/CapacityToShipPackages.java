// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

public class CapacityToShipPackages {
    public int shipWithinDays(int[] weights, int days) {
        int l = 0, r = 0;

        for (int w : weights) {
            l = Math.max(l, w);
            r += w;
        }
        int ans = r;
        while (l <= r) {
            int m = (r + l) / 2;
            int cap = 0, day = 1;
            boolean can = true;
            for (int ele : weights) {
                if (cap + ele > m) {
                    day++;
                    if (day > days) {
                        can = false;
                        break;
                    }
                    cap = ele;
                } else {
                    cap += ele;
                }
            }
            if (can) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
}
