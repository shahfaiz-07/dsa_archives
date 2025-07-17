// https://leetcode.com/problems/poor-pigs/
public class PoorPigs {

    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int totalTrials = minutesToTest/minutesToDie;
        int T = totalTrials + 1;

        // T^(pigs) = buckets
        // pigs = log_T(buckets)

        return (int)Math.ceil(Math.log10(buckets)/Math.log10(T));
    }
}