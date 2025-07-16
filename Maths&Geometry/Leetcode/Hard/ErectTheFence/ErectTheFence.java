// https://leetcode.com/problems/erect-the-fence/
import java.util.*;
public class ErectTheFence {
    class Pair {
        int first, second;
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public boolean equals(Object b) {
            if(!(b instanceof Pair)) return false;
            Pair b1 = (Pair)b;
            return this.first == b1.first && this.second == b1.second;
        }

        @Override
        public int hashCode() {
            return Objects.hash(first, second);
        }
    }
    int equation(Pair p1, Pair p2, Pair p3) {
        // m23 - m21 > 0 (for convex in lower half)
        // (y3-y2)/(x3-x2) - (y2-y1)/(x2-x1)
        // (y3-y2)(x2-x1) - (y2-y1)(x3-x2)
        int x1 = p1.first, x2 = p2.first, x3 = p3.first;
        int y1 = p1.second, y2 = p2.second, y3 = p3.second;

        return (y3-y2)*(x2-x1) - (y2-y1)*(x3-x2);
    }
    public int[][] outerTrees(int[][] trees) {

        List<Pair> lower = new ArrayList<>(), upper = new ArrayList<>();

        // looking from left bottom to right
        Arrays.sort(trees, (a, b) -> {
            if(a[0] == b[0]) return a[1] - b[1];
            return a[0] - b[0];
        });

        for(int[] point: trees) {
            int l = lower.size(), u = upper.size();
            // positive for lower negative for above for convexity
            while(l >= 2 && equation(lower.get(l-2), lower.get(l-1), new Pair(point[0], point[1])) < 0) {
                l--;
                lower.remove(l);
            }
            while(u >= 2 && equation(upper.get(u-2), upper.get(u-1), new Pair(point[0], point[1])) > 0) {
                u--;
                upper.remove(u);
            }

            lower.add(new Pair(point[0], point[1]));
            upper.add(new Pair(point[0], point[1]));
        }

        Set<Pair> st = new HashSet<>();

        for(Pair point: lower) {
            st.add(point);
        }
        for(Pair point: upper) {
            st.add(point);
        }

        int[][] ans = new int[st.size()][2];
        int ind = 0;
        for(Pair point: st) {
            ans[ind][0] = point.first;
            ans[ind][1] = point.second;
            ind++;
        }

        return ans;
    }
}
