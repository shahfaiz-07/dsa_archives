// https://leetcode.com/problems/candy/
public class Candy {
    // SC = O(N)
    public int candy(int[] ratings) {
        // left
        int[] left = new int[ratings.length];
        left[0] = 1;
        for (int i = 1; i < ratings.length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }
        int sum = left[ratings.length - 1];
        int prev = 1;
        for (int i = ratings.length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                prev++;
            } else {
                prev = 1;
            }
            sum += Math.max(left[i], prev);
        }
        return sum;
    }
}