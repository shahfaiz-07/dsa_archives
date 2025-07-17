// https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
import java.util.*;
public class NumberofWaystoReorderArraytoGetSameBST {
    List<List<Long>> P;
    long MOD = (long) 1e9 + 7;

    long solve(List<Integer> nums) {
        int n = nums.size();
        if(n < 3) return 1;
        List<Integer> left = new ArrayList<>(), right = new ArrayList<>();
        for (int i = 1; i < n; i++) {
            if (nums.get(i) < nums.get(0)) {
                left.add(nums.get(i));
            } else {
                right.add(nums.get(i));
            }
        }
        long x = solve(left) % MOD, y = solve(right) % MOD;
        // keeping the relative ordering same (combination) we have to arrange them in (n-1) places - we can choose either to combine left or right elements
        long z = P.get(n - 1).get(left.size());

        return (((x * y) % MOD) * z) % MOD;
    }

    public int numOfWays(int[] nums) {
        int n = nums.length;
        P = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            P.add(new ArrayList<>());
            P.get(i).add(1L);
            // Pascals Triangle to calculate nCr
            for (int j = 1; j < i; j++) {
                P.get(i).add((P.get(i - 1).get(j - 1) + P.get(i - 1).get(j)) % MOD);
            }
            P.get(i).add(1L);
        }
        List<Integer> l = Arrays.stream(nums).boxed().collect(Collectors.toList());
        return (int) solve(l) - 1;
    }
}
