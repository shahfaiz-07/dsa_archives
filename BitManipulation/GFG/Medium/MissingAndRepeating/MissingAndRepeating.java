// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

import java.util.ArrayList;

public class MissingAndRepeating {
    ArrayList<Integer> findTwoElement(int arr[]) {
        // code here
        int allXor = 0;
        for(int i=0; i<arr.length; i++) {
            allXor ^= arr[i];
            allXor ^= (i+1);
        }
        
        // a ^ b
        int diff = (allXor & ~(allXor - 1));
        int setBit = 0, unsetBit = 0;
        for(int i=0; i<arr.length; i++) {
            if((arr[i] & diff) != 0) setBit ^= arr[i];
            else unsetBit ^= arr[i];
            
            if(((i+1) & diff) != 0) setBit ^= (i+1);
            else unsetBit ^= (i+1);
        }
        
        int cnt = 0;
        for(int i=0; i<arr.length; i++) {
            if(arr[i] == setBit) {
                cnt++;
                if(cnt == 2) break;
            }
        }
        ArrayList<Integer> ans = new ArrayList<>();
        if(cnt == 2) {
            ans.add(setBit);
            ans.add(unsetBit);
        } else {
            ans.add(unsetBit);
            ans.add(setBit);
        }
        return ans;
    }
}
