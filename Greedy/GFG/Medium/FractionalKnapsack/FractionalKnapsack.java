// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Pair {

    int val, wt;

    Pair(int val, int wt) {
        this.val = val;
        this.wt = wt;
    }
}
public class FractionalKnapsack {
    double fractionalKnapsack(List<Integer> values, List<Integer> weights, int w) {
        // code here
        List<Pair> p = new ArrayList<>();
        for(int i=0; i<values.size(); i++) {
            p.add(new Pair(values.get(i), weights.get(i)));
        }
        Collections.sort(p, (a, b) -> Double.compare((double)b.val / b.wt, (double)a.val / a.wt));
        double value = 0.0;
        int i=0;
        while(i < values.size() && w != 0) {
            int weight = p.get(i).wt, v = p.get(i).val;
            if(w - weight >= 0) {
                w -= weight;
                value += v;
            } else {
                double vpw = (double)v/weight;
                value += w*vpw;
                w = 0;
            }
            i++;
        }
        return value;
    }
}
