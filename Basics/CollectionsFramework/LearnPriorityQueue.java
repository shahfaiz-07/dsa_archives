import java.util.Comparator;
import java.util.PriorityQueue;

public class LearnPriorityQueue {
    public static void main(String[] args) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        pq.offer(4);
        pq.offer(1);
        pq.offer(22);
        pq.offer(17);
        pq.offer(2);
        System.out.println(pq); // Maintains a minHeap
        
        pq.poll();
        System.out.println(pq); // Maintains a minHeap
        
        // For reversing the priority you may use a short-hand
        PriorityQueue<Integer> rpq = new PriorityQueue<>(Comparator.reverseOrder());
        rpq.offer(4);
        rpq.offer(1);
        rpq.offer(22);
        rpq.offer(17);
        rpq.offer(2);
        System.out.println(rpq); // Maintains a maxHeap
        
        rpq.poll();
        System.out.println(rpq); // Maintains a maxHeap
    }
}
