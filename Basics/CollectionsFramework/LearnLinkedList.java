import java.util.LinkedList;

public class LearnLinkedList {
    public static void main(String[] args) {
        LinkedList<String> ll = new LinkedList<>();

        // # add(ele) OR # add(index, ele)
        ll.add("Hello");
        ll.add("World");
        ll.add(0, "Jerry");
        System.out.println(ll);

        // # addAll(Collection) OR # addAll(index, Collection)
        // # addFirst, # addLast

        // # offer(ele) - add at last
        ll.offer("Something");
        System.out.println(ll);

        // # offerFirst(ele), # offerLast(ele)

        // Difference Between 'add' and 'offer' ? - If you are unable to add the element successfully the add function throws an excpetion and returns 'true' if the operation is successfull, whereas offer function returns either 'true' or 'false'

        // # contains(ele)

        // # clear

        // # element() and # peek() - return head of the list
        // for empty list, element() throws an Exception whereas peek() returns 'null'
        // # peekFirst(), # peekLast()

        // # remove() and # poll() - returns and remove the head of the list
        // for empty list remove() throws an exception whereas poll() returns 'null'
        // # pollFirst(), # pollLast()
    }
}
