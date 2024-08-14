import java.util.Arrays;

public class SelectionSort {
    static void selectionSort(int arr[]) {
        for (int i = 0; i < arr.length - 1; i++) {
            int s = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[s]) {
                    s = j;
                }
            }
            if (s != i) { // check if the current element is the smallest
                int t = arr[i];
                arr[i] = arr[s];
                arr[s] = t;
            }
        }
    }

    public static void main(String[] args) {
        int arr[] = { 1, 4, 5, 2, 5, 6, 5, 0, 2, 1 };
        System.out.println("Before : " + Arrays.toString(arr));
        selectionSort(arr);
        System.out.println("After : " + Arrays.toString(arr));
    }
}