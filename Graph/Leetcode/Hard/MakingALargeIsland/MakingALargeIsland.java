// https://leetcode.com/problems/making-a-large-island/

import java.util.Set;
import java.util.TreeSet;

public class MakingALargeIsland {

    class DisjointSet {
        int[] par, size;
        DisjointSet(int V) {
            par = new int[V];
            size = new int[V];
            for(int i=0; i<V; i++) {
                par[i] = i;
                size[i] = 1;
            }
        }

        int findPar(int x) {
            if(par[x] == x) return x;
            par[x] = findPar(par[x]);
            return par[x];
        }

        void unionBySize(int u, int v) {
            int up_u = findPar(u), up_v = findPar(v);
            if(up_v == up_u) return;

            if(size[up_u] < size[up_v]) {
                par[up_u] = up_v;
                size[up_v] += size[up_u]; 
            } else {
                par[up_v] = up_u;
                size[up_u] += size[up_v];
            }
        }
    }
    public int largestIsland(int[][] grid) {
        int n = grid.length;
        DisjointSet ds = new DisjointSet(n * n);
        int[] delr = {0, 1, 0, -1};
        int[] delc = {1, 0, -1, 0};
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    for(int k=0; k<4; k++) {
                        int x = i + delr[k], y = j + delc[k];
                        if(x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 1) {
                            int val = n*i + j;
                            int val1 = n*x + y;
                            ds.unionBySize(val, val1);
                        }
                    }
                }
            }
        }
        int maxSize = 0;
        for(int i=0; i<n; i++) {
            maxSize = Math.max(maxSize, ds.size[i]);
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) {
                    Set<Integer> uniques = new TreeSet<>();
                    for(int k=0; k<4; k++) {
                        int x = i + delr[k], y = j + delc[k];
                        if(x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 1) {
                            int val1 = n*x + y;
                            uniques.add(ds.findPar(val1));
                        }
                    }
                    int size = 0;
                    for(int unique: uniques) {
                        size = size + ds.size[unique];
                    }
                    maxSize = Math.max(maxSize, size + 1);
                }
            }
        }
        return maxSize;
    }
}