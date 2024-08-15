import java.util.ArrayList;
import java.util.Collections;

public class ReverseArray {
    static void reverse(ArrayList<Integer> arr, int index) {
        if(index >= arr.size()/2) {
            return;
        }
        Collections.swap(arr, index, arr.size() - index - 1);
        reverse(arr, index + 1);
    }
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(1);
        arr.add(2);
        arr.add(3);
        arr.add(4);
        arr.add(5);
        arr.add(6);
        System.out.println(arr);
        reverse(arr, 0);
        System.out.println(arr);
    }
}
