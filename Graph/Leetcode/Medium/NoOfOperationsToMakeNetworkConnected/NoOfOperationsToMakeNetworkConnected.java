// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

import java.util.Arrays;

public class NoOfOperationsToMakeNetworkConnected {
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
            if(par[x] == x) return x;
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
    public int makeConnected(int n, int[][] connections) {
        int xtraEdges = 0;
        DisjointSet ds = new DisjointSet(n);
        for(int[] edge: connections) {
            if(ds.findPar(edge[0]) == ds.findPar(edge[1])) {
                xtraEdges++;
            } else {
                ds.unionBySize(edge[0], edge[1]);
            }
        }
        int components = 0;
        System.out.println(Arrays.toString(ds.par));
        for(int i=0; i<n; i++) {
            if(ds.par[i] == i) {
                components++;
            }
        }
        int ans = components - 1;
        return xtraEdges >= ans ? ans : -1;
    }
}
