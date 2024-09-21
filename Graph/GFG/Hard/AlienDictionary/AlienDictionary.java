// https://www.geeksforgeeks.org/problems/alien-dictionary/1
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class AlienDictionary {

    void topoSort(List<List<Integer>> adj, int curr, boolean visited[], Deque<Integer> stack) {
        visited[curr] = true;
        for(int neighbor: adj.get(curr)) {
            if(!visited[neighbor]) {
                topoSort(adj, neighbor, visited, stack);
            }
        }
        stack.push(curr);
    }
    public String findOrder(String[] dict, int n, int k) {
        // Write your code here
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<k; i++) {
            adj.add(new ArrayList<>());
        }
        for(int i=0; i<n-1; i++) {
            // why a particular word comes before other
            for(int ind=0; ind<dict[i].length() && ind<dict[i+1].length(); ind++) {
                if(dict[i].charAt(ind) != dict[i+1].charAt(ind)) {
                    adj.get(dict[i].charAt(ind) - 'a').add(dict[i+1].charAt(ind) - 'a');
                    break;
                }
            }
        }
        Deque<Integer> stack = new ArrayDeque<>();
        boolean visited[] = new boolean[k];
        for(int i=0; i<k; i++) {
            if(!visited[i]) {
                topoSort(adj, i, visited, stack);
            }
        }
        String str = "";
        while(!stack.isEmpty()) {
            str += (char)(stack.poll()+97);
        }
        return str;
    }
}