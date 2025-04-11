// https://leetcode.com/problems/online-stock-span/

import java.util.ArrayDeque;
import java.util.Deque;

public class OnlineStockSpan {

    class Pair {
    int first, second;
    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
class StockSpanner {
    Deque<Pair> st;
    int c;
    public StockSpanner() {
        st = new ArrayDeque<>();
        c = 0;
    }
    
    public int next(int price) {
        while(!st.isEmpty() && price >= st.peek().first) {
            st.pop();
        }
        int ind = st.isEmpty() ? -1 : st.peek().second;
        st.push(new Pair(price, c));
        c++;
        return c - ind - 1;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
}