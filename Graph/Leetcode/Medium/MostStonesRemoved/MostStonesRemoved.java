// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

public class MostStonesRemoved {
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
    public int removeStones(int[][] stones) {
        // to connect stones here we treat every row as an individual node and every column as an individual node.
        // for 5*4 matrix 
        // rows - 0 1 2 3 4, cols - 5(0th col) 6 7 8
        // col = col + row
        // if a stone belongs to 0th row and 0th col, we combine nodes 0 and 5

        int n = stones.length;
        int r = 0, c = 0;
        for(int[] it: stones) {
            r = Math.max(it[0], r);
            c = Math.max(it[1], c);
        }

        r += 1;
        c += 1;

        DisjointSet ds = new DisjointSet(r + c);
        boolean[] visited = new boolean[r + c];
        for(int[] it: stones) {
            ds.unionBySize(it[0], it[1] + r);
            visited[it[0]] = true; 
            visited[it[1] + r] = true; 
        }
        
        int count = 0;
        for(int i=0; i<r+c; i++) {
            if(visited[i] && ds.findPar(i) == i) {
                count++;
            }
        }

        return n - count;
    }
}
