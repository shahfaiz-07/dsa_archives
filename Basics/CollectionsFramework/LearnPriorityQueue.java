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

        // STORING PAIRS IN PRIORITY QUEUE BASED ON WEIGHT OF FIRST AND THEN SECOND VALUE

        PriorityQueue<Pair> pairPQ = new PriorityQueue<>((a, b) -> {
            if(a.first == b.first) 
                return a.second - b.second;
            return a.first - b.first;
        });

        pairPQ.add(new Pair(5,2));
        pairPQ.add(new Pair(2,9));
        pairPQ.add(new Pair(6,8));
        pairPQ.add(new Pair(2,5));
        pairPQ.add(new Pair(2,10));
        pairPQ.add(new Pair(10,5));

        System.out.println(pairPQ.poll());
        System.out.println(pairPQ.poll());
        System.out.println(pairPQ.poll());
        System.out.println(pairPQ.poll());
        System.out.println(pairPQ.poll());
    }
}

class Pair {
    int first, second;
    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public String toString() {
        return "{"+first+", "+second+"}";
    }
}
