// https://leetcode.com/problems/koko-eating-bananas/

public class KokoEatingBananas {
    int timeTaken(int[] piles, double k) {
        int h = 0;
        for (int bananas : piles) {
            h += Math.ceil(bananas / k);
        }
        return h;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int u = piles[0];
        for (int i = 1; i < piles.length; i++) {
            if (piles[i] > u) {
                u = piles[i];
            }
        }
        int l = 1;
        while (l <= u) {
            int m = u - (u - l) / 2;
            int time = timeTaken(piles, m);
            if (time > h) {
                l = m + 1;
            } else {
                u = m - 1;
            }
        }
        return l;
    }
}
