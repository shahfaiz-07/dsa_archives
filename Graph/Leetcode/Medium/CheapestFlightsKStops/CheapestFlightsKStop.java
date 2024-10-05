// https://leetcode.com/problems/cheapest-flights-within-k-stops/

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;

class Tuple {

    int price, stops, node;

    Tuple(int price, int stops, int node) {
        this.price = price;
        this.stops = stops;
        this.node = node;
    }
}

class Pair {

    int first, second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
public class CheapestFlightsKStop {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        // adjacency list
        List<List<Pair>> adj = new ArrayList<>();

        for(int i=0; i<n; i++) {
            adj.add(new ArrayList<>());
        }

        for(int[] edge: flights) {
            adj.get(edge[0]).add(new Pair(edge[1], edge[2]));
        }

        int minPrice[] = new int[n];
        Arrays.fill(minPrice, Integer.MAX_VALUE);
        minPrice[src] = 0;

        Deque<Tuple> que = new ArrayDeque<>();
        que.offer(new Tuple(0, 0, src));

        while(!que.isEmpty()) {
            Tuple curr = que.poll();
            int stops = curr.stops, price = curr.price, node = curr.node;

            if(stops > k) continue;
            for(Pair neighbor: adj.get(node)) {

                int newPrice = neighbor.second + price;
                if(newPrice < minPrice[neighbor.first] && stops <= k) {
                    minPrice[neighbor.first] = newPrice;
                    que.offer(new Tuple(newPrice, stops + 1, neighbor.first));
                }
            }
        }

        return minPrice[dst] == Integer.MAX_VALUE ? -1 : minPrice[dst];
    }
}
