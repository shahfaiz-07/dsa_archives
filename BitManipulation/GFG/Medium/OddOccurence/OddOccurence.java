// https://www.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1
public class OddOccurence {
    public int[] twoOddNum(int Arr[], int N) {
        // code here
        long XOR = 0;
        for (int i = 0; i < N; i++) {
            XOR = XOR ^ Arr[i];
        }
        long sep = (XOR & (XOR - 1)) ^ XOR;
        int b1 = 0, b2 = 0;
        for (int i = 0; i < N; i++) {
            if ((sep & Arr[i]) == 0) {
                b1 = b1 ^ Arr[i];
            } else {
                b2 = b2 ^ Arr[i];
            }
        }
        if (b1 > b2) {
            return new int[]{b1, b2};
        }
        return new int[]{b2, b1};
    }
}
