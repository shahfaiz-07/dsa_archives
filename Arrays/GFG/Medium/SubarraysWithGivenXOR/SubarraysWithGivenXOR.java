// https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

import java.util.HashMap;
import java.util.Map;

public class SubarraysWithGivenXOR {
    public long subarrayXor(int arr[], int k) {
        // code here
        Map<Integer, Integer> hash = new HashMap<>();
        int c = 0, XOR = 0;
        hash.put(0, 1);
        for(int ele: arr) {
            XOR ^= ele;
            int x_k = XOR ^ k;
            int val = hash.getOrDefault(x_k, 0);
            if(val != 0) {
                c += val;
            }
            hash.compute(XOR, (key, v) -> v == null ? 1 : v + 1);
        }
        return c;
    }
}
