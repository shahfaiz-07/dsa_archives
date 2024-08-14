import java.util.Arrays;

public class InsertionSort {
    static void insertionSort(int arr[]) {
        for (int i = 1; i < arr.length; i++) {
            int j = i - 1, curr = arr[i];
            while (j >= 0 && curr < arr[j]) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = curr;
        }
    }

    public static void main(String[] args) {
        int arr[] = { 1, 4, 5, 2, 5, 6, 5, 0, 2, 1 };
        System.out.println("Before : " + Arrays.toString(arr));
        insertionSort(arr);
        System.out.println("After : " + Arrays.toString(arr));
    }
}
