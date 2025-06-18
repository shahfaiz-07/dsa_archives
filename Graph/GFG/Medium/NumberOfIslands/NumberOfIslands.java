// https://www.geeksforgeeks.org/problems/number-of-islands/0
import java.util.*;
public class NumberOfIslands {
    class DisjointSet {
        int[] par, size;
        DisjointSet(int V) {
            par = new int[V];
            size = new int[V];
            
            for(int i=0; i<V; i++) {
                par[i] = i;
            }
        }
        
        int findPar(int x) {
            if(par[x] == x) return x;
            par[x] = findPar(par[x]);
            return par[x];
        }
        
        void union(int u, int v) {
            int up_u = par[u], up_v = par[v];
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
    int valueOf(int row, int col, int i, int j) {
        return i*col + j;
    }
    public List<Integer> numOfIslands(int rows, int cols, int[][] operators) {
        // Your code here
        DisjointSet ds = new DisjointSet(rows * cols);
        int[][] dels = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int count = 0;
        List<Integer> ans = new ArrayList<>();
        for(int[] op: operators) {
            int val = valueOf(rows, cols, op[0], op[1]);
            if(ds.size[val] == 0) {
                ds.size[val] = 1;
                count++;
                for(int[] del: dels) {
                    int x = op[0] + del[0], y = op[1] + del[1];
                    if(x >= 0 && y >= 0 && x < rows && y < cols) {
                        int val1 = valueOf(rows, cols, x, y);
                        if(ds.size[val1] != 0) {
                            if(ds.findPar(val1) != ds.findPar(val)) {
                                count--;
                            }
                            ds.union(val1, val);
                        }
                    }
                }
            }
            ans.add(count);
        }
        return ans;
    }
}