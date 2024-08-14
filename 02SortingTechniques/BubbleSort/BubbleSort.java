import java.util.Arrays;

public class BubbleSort {
    static void bubbleSort(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            boolean swapped = false; // check for already sorted array
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swapped = true;
                    int t = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = t;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        int arr[] = { 1, 4, 5, 2, 5, 6, 5, 0, 2, 1 };
        System.out.println("Before : " + Arrays.toString(arr));
        bubbleSort(arr);
        System.out.println("After : " + Arrays.toString(arr));
    }
}
