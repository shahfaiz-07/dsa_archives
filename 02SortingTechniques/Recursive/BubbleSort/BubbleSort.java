import java.util.Arrays;

public class BubbleSort {
    static void swapElements(int arr[], int start, int index) {
        if (index == arr.length - start - 1) {
            return;
        }
        if (arr[index] > arr[index + 1]) {
            int t = arr[index];
            arr[index] = arr[index + 1];
            arr[index + 1] = t;
        }
        swapElements(arr, start, index + 1);
    }

    static void bubbleSort(int arr[], int index) {
        if (index == arr.length - 1) {
            return;
        }
        swapElements(arr, index, 0);
        bubbleSort(arr, index + 1);
    }

    public static void main(String[] args) {
        int arr[] = { 1, 4, 5, 2, 5, 6, 5, 0, 2, 1 };
        System.out.println("Before : " + Arrays.toString(arr));
        bubbleSort(arr, 0);
        System.out.println("After : " + Arrays.toString(arr));
    }
}
