// https://leetcode.com/problems/pascals-triangle/

import java.util.ArrayList;
import java.util.List;

public class PascalTriangle {

    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        ans.add(new ArrayList<>());
        ans.get(0).add(1);
        for (int i = 1; i < numRows; i++) {
            ans.add(new ArrayList<>());
            ans.get(i).add(1);
            for (int j = 1; j < i; j++) {
                ans.get(i).add(ans.get(i - 1).get(j) + ans.get(i - 1).get(j - 1));
            }
            ans.get(i).add(1);
        }
        return ans;
    }

    public static int nCr(int n, int r) {
        int res = 1;
        // (n) * (n-1) * ... * (n-r+1) / 1 * 2 * ... * r
        for (int i = 0; i < r; i++) {
            res = res * (n - i) / (i + 1);
        }
        return res;
    }
    public static void main(String[] args) {
        System.out.println(nCr(10, 3));
    }
}