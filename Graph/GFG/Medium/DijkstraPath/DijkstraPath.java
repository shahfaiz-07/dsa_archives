// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

class Pair {

    int first, second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
public class DijkstraPath {
    public List<Integer> shortestPath(int n, int m, int edges[][]) {
        //  Code Here.
        ArrayList<ArrayList<Pair>> adj = new ArrayList<>();
        
        for(int i=0; i<=n; i++) {
            adj.add(new ArrayList<>());
        }
        
        for(int[] edge: edges) {
            adj.get(edge[0]).add(new Pair(edge[1], edge[2])); // node and weight
            adj.get(edge[1]).add(new Pair(edge[0], edge[2]));
        }
        
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> {
           return a.first - b.first; // first is distance, second is node
        });
        
        int minDist[][] = new int[n + 1][2]; // first is previous node and second is minDist
        
        for(int i=1; i<=n; i++) {
            minDist[i][1] = Integer.MAX_VALUE;
            minDist[i][0] = -1;
        }
        
        minDist[1][1] = 0;
        
        pq.offer(new Pair(0, 1));
        
        while(!pq.isEmpty()) {
            Pair curr = pq.poll();
            int node = curr.second, dist = curr.first;
            
            pq.remove(curr);
            
            for(Pair neighbor: adj.get(node)) {
                int newDist = neighbor.second + dist;
                if(minDist[neighbor.first][1] > newDist) {
                    minDist[neighbor.first][0] = node;
                    minDist[neighbor.first][1] = newDist;
                    pq.offer(new Pair(newDist, neighbor.first));
                }
            }
        }
        
        if(minDist[n][1] == Integer.MAX_VALUE) {
            List<Integer> ans = new ArrayList<>();
            ans.add(-1);
            return ans;
        }
        
        List<Integer> path = new ArrayList<>();
        path.add(minDist[n][1]);
        int node = n;
        while(node != -1) {
            path.add(node);
            node = minDist[node][0];
        }
        int l = 1, r = path.size() - 1;
        
        while(l < r) {
            Collections.swap(path, l, r);
            l++;
            r--;
        }
        return path;
    }
}
