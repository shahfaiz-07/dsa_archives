// https://leetcode.com/problems/task-scheduler/
import java.util.ArrayDeque;
import java.util.Comparator;
import java.util.Deque;
import java.util.PriorityQueue;

public class TaskScheduler {
    class Pair {
        int first, second;
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    public int leastInterval(char[] tasks, int n) {
        int freqs[] = new int[26];
        for(char task: tasks) {
            freqs[task - 'A']++;
        }

        PriorityQueue<Integer> heap = new PriorityQueue<>(Comparator.reverseOrder());

        for(int freq: freqs) {
            if(freq > 0) {
                heap.offer(freq);
            }
        }
        int time = 0;
        Deque<Pair> queue = new ArrayDeque<>();
        while(!heap.isEmpty() || !queue.isEmpty()) {
            if(!queue.isEmpty()) {
                int outTime = queue.peek().second;
                int ele = queue.peek().first;
                if(time == outTime) {
                    heap.offer(ele);
                    queue.poll();
                }
            }
            if(!heap.isEmpty()) {
                int ele = heap.peek();
                if(ele > 1) {
                    queue.offer(new Pair(ele - 1, time + n + 1));
                }
                heap.poll();
            }
            time++;
        }
        return time;
    }
}
