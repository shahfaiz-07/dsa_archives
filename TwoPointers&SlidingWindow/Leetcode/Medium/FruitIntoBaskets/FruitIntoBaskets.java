// https://leetcode.com/problems/fruit-into-baskets/
import java.util.HashMap;
import java.util.Map;
public class FruitIntoBaskets {
    public int totalFruit(int[] fruits) {
        int l = 0, r = 0, max = 0;
        Map<Integer, Integer> mp = new HashMap<>();
        while (r < fruits.length) {
            mp.compute(fruits[r], (k, v) -> v == null ? 1 : v + 1);
            while (mp.size() > 2) {
                if (mp.compute(fruits[l], (k, v) -> v - 1) == 0) {
                    mp.remove(fruits[l]);
                }
                l++;
            }
            max = Math.max(max, r - l + 1);
            r++;
        }
        return max;
    }
}
