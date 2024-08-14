import java.util.Arrays;

public class SelectionSort {
    static int findSmallest(int arr[], int start, int smallestIndex) {
        if (start == arr.length) {
            return smallestIndex;
        }
        smallestIndex = arr[smallestIndex] < arr[start] ? smallestIndex : start;
        return findSmallest(arr, start + 1, smallestIndex);
    }

    static void selectionSort(int arr[], int index) {
        if (index == arr.length) {
            return;
        }
        int s = findSmallest(arr, index, index);
        if (s != index) {
            int t = arr[s];
            arr[s] = arr[index];
            arr[index] = t;
        }
        selectionSort(arr, index + 1);
    }

    public static void main(String[] args) {
        int arr[] = { 1, 4, 5, 2, 5, 6, 5, 0, 2, 1 };
        System.out.println("Before : " + Arrays.toString(arr));
        selectionSort(arr, 0);
        System.out.println("After : " + Arrays.toString(arr));
    }
}
