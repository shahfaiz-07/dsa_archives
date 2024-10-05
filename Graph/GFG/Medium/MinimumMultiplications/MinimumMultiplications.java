// https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

class Pair {

    int steps, val;

    Pair(int steps, int val) {
        this.steps = steps;
        this.val = val;
    }
}
public class MinimumMultiplications {
    int minimumMultiplications(int[] arr, int start, int end) {

        // Your code here
        // applying dijkstra - what are the nodes?
        // 0 - 9999 as why have a modulo 10^5
        final int MOD = (int) 1e5;
        int minSteps[] = new int[MOD];

        Arrays.fill(minSteps, Integer.MAX_VALUE);
        minSteps[start] = 0;
        Deque<Pair> que = new ArrayDeque<>();

        que.offer(new Pair(0, start));

        while (!que.isEmpty()) {
            Pair curr = que.poll();
            int steps = curr.steps, val = curr.val;
            if (val == end) {
                return steps;
            }
            int newSteps = steps + 1;
            for (int ele : arr) {
                int newVal = (ele * val) % MOD;
                if (minSteps[newVal] > newSteps) {
                    minSteps[newVal] = newSteps;
                    que.offer(new Pair(newSteps, newVal));
                }
            }
        }
        return -1;
    }
}
