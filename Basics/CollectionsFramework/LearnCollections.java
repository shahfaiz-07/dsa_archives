
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class LearnCollections {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>();
        list.add(0);
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);
        list.add(6);
        list.add(7);

        // swap(Collection, index, index);
        System.out.println(list);
        Collections.swap(list, 0, 5);
        System.out.println(list);
    }
}
