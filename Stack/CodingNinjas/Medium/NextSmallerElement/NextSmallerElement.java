// https://www.naukri.com/code360/problems/next-smaller-element_1112581

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;

public class NextSmallerElement {
    static ArrayList<Integer> nextSmallerElement(ArrayList<Integer> arr, int n){
        // Write your code here.
        Deque<Integer> st = new ArrayDeque<>();
        ArrayList<Integer> ans = new ArrayList<>(Collections.nCopies(n, -1));
        
        for(int i=n - 1; i >= 0; i--) {
            while(!st.isEmpty() && st.peek() >= arr.get(i)) {
                st.pop();
            }
            if (!st.isEmpty()) {
                ans.set(i, st.peek());
            }
            st.push(arr.get(i));
        }
        return ans;
    }
}
