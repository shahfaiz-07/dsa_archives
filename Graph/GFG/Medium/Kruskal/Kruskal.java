// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
import java.util.*;
class DisjointSet {
    int[] par;
    int[] size;
    DisjointSet(int V) {
        par = new int[V];
        size = new int[V];
        for(int i=0; i<V; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }
    
    int findPar(int x) {
        if(par[x] == x) {
            return x;
        }
        par[x] = findPar(par[x]);
        return par[x];
    }
    
    void unionBySize(int u, int v) {
        int up_u = findPar(u);
        int up_v = findPar(v);
        
        if(up_u == up_v) return;
        
        if(size[up_u] < size[up_v]) {
            par[up_u] = up_v;
            size[up_v] += size[up_u]; 
        } else {
            par[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
}
class Tuple {
    int wt, u, v;
    Tuple(int wt, int u, int v) {
        this.wt = wt;
        this.u = u;
        this.v = v;
    } 
}
public class Kruskal {
    
    static int spanningTree(int V, int E, List<List<int[]>> adj) {
        // Code Here.
        List<Tuple> edges = new ArrayList<>();
        for(int i=0; i<adj.size(); i++) {
            int u = i;
            for(int j=0; j<adj.get(i).size(); j++) {
                int v = adj.get(i).get(j)[0];
                int wt = adj.get(i).get(j)[1];
                edges.add(new Tuple(wt, u, v));
            }
        }
        
        Collections.sort(edges, (a, b) -> {
            return a.wt - b.wt;
        });
        
        int sum = 0;
        
        DisjointSet ds = new DisjointSet(V);
        for(Tuple edge: edges) {
            int wt = edge.wt;
            int u = edge.u;
            int v = edge.v;
            
            if(ds.findPar(u) != ds.findPar(v)) {
                sum += wt;
                ds.unionBySize(u, v);
            }
        }
        return sum;
    }
}