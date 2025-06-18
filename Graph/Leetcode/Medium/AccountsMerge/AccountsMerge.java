// https://leetcode.com/problems/accounts-merge/

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class AccountsMerge {

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

        void union(int u, int v) {
            int up_u = findPar(u), up_v = findPar(v);

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
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<String, Integer> mp = new HashMap<>();
        int V = accounts.size();
        DisjointSet ds = new DisjointSet(V);
        for(int i=0; i<V; i++) {
            for(int j=1; j<accounts.get(i).size(); j++) {
                String email = accounts.get(i).get(j);
                int ind = mp.getOrDefault(email, -1);
                if(ind == -1) {
                    mp.put(email, i);
                } else {
                    ds.union(i, ind);
                }
            }
        }
        List<String>[] temp = new List[V];
        for(Map.Entry<String, Integer> e: mp.entrySet()) {
            String email = e.getKey();
            int val = ds.findPar(e.getValue());
            if(temp[val] == null) {
                temp[val] = new ArrayList<>();
            }
            temp[val].add(email);
        }
        List<List<String>> ans = new ArrayList<>();
        for(int i=0; i<V; i++) {
            if(temp[i] == null) continue;
            List<String> t = new ArrayList<>();
            t.add(accounts.get(i).get(0));
            Collections.sort(temp[i]);
            for(int j=0; j<temp[i].size(); j++) {
                t.add(temp[i].get(j));
            }
            ans.add(t);
        }

        return ans;
    }
}