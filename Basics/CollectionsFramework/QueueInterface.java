import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class QueueInterface {
    public static void main(String[] args) {
        // Methods of Queue Interface
        // # add(ele) OR # add(index, ele)

        // # addAll(Collection) OR # addAll(index, Collection)

        // # size(), # clear()
        
        // # remove(), # remove(index), # remove(Object)

        // # get(index), # set(index, ele), # indexOf(ele), # lastIndexOf(ele)

        // # isEmpty(), # contains(ele), # containsAll(Collection)

        // # offer(ele), # poll(), # element(), # peek()

        // -------------------------------- MOST USEFULL -------------------------------
        // offer, poll, peek, size
        // -----------------------------------------------------------------------------

        // Queue using LinkedList - FIFO
        Queue<String> que = new LinkedList<>();
        que.offer("3");
        que.offer("2");
        que.offer("4");
        que.offer("1");
        System.out.println(que);

        // Queue using Priority Queue - Comparator based
        Queue<String> pQue = new PriorityQueue<>();
        pQue.offer("3");
        pQue.offer("2");
        pQue.offer("4");
        pQue.offer("1");
        System.out.println(pQue);
    }
}
