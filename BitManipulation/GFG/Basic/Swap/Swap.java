// https://www.geeksforgeeks.org/problems/swap-two-numbers3844/1

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Swap {
    static List<Integer> get(int a,int b)
    {
        // code here
        a = a^b;
        b = a^b;
        a = a^b;
        return new ArrayList<>(Arrays.asList(a, b));
    }
    public static void main(String[] args) {
        System.out.println(get(3, 4));
    }
}
