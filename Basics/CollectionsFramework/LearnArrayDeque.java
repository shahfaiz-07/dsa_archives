// Generally prefered over LinkedList to Implement Deques

import java.util.ArrayDeque;
import java.util.Deque;

public class LearnArrayDeque {
    public static void main(String[] args) {
        // Use the Deque interface for better performance

        Deque<String> dq = new ArrayDeque<>();

        // # addFirst(ele), # addLast(ele) - returns IllegalStateException if queue is capacity restricted and no further elements can be inserted
        // # offerFirst(ele), # offerLast(ele), #offer(ele) - returns true or false

        // # contains(ele)

        // # getFirst(), # getLast(), # clear()

        // # element()

        // # isEmpty()

        // # peekFirst(), # peekLast()
        
        // # pollFirst(), # pollLast()

        // # size()

        // MOST USEFUL

        // # offerFirst(), # offerLast()
        // # pollFirst(), # pollLast()
        // # peekFirst(), # peekLast()
        // # isEmpty(), size()

        dq.offerFirst("1");
        dq.offerFirst("2");
        dq.offerLast("3");
        dq.offerFirst("4");

        System.out.println(dq);

        System.out.println(dq.peekFirst() + ", " + dq.peekLast());
    }
}
