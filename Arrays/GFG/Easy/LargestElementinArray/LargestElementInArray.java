// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/
public class LargestElementInArray {

    static int largest(int arr[]) {
        int m = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > m) {
                m = arr[i];
            }
        }
        return m;
    }

    public static void main(String[] args) {
        int arr[] = {1, 5, 3, 7, 8, 4, 9, 0, 6, 4};
        System.out.println(largest(arr));
    }
}
