
import java.util.Arrays;

// https://leetcode.com/problems/move-zeroes/description/

public class MoveZerosToEnd {

    static void moveZeroes(int arr[]) {
        if (arr.length <= 1) {
            return;
        }
        int l = arr[0] == 0 ? 0 : 1, r = 1;
        while (r < arr.length) {
            if (arr[r] != 0) {
                while (l < r && arr[l] != 0) {
                    l++;
                }
                if (l == r) {
                    r++;
                } else {
                    arr[l] = arr[r];
                    arr[r] = 0;
                }
            } else {
                r++;
            }
        }
    }

    public static void main(String[] args) {
        int arr[] = {0, 1, 0, 3, 12};
        System.out.println(Arrays.toString(arr));
        moveZeroes(arr);
        System.out.println(Arrays.toString(arr));
    }
}
