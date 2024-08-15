import java.util.*;

public class QuickSort {
    static int partition(int arr[], int l, int r) {
        int pivot = arr[l];
        int i = l;
        int j = r;

        while (i < j) {
            while (arr[i] <= pivot && i <= r - 1) {
                i++;
            }

            while (arr[j] > pivot && j >= l + 1) {
                j--;
            }
            if (i < j) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
        int t = arr[l];
        arr[l] = arr[j];
        arr[j] = t;
        return j;
    }

    static void quickSort(int arr[], int l, int r) {
        if (l < r) {
            int p = partition(arr, l, r);
            quickSort(arr, l, p - 1);
            quickSort(arr, p + 1, r);
        }
    }

    public static void main(String[] args) {
        int arr[] = { 1, 4, 5, 2, 5, 6, 5, 0, 2, 1 };
        System.out.println("Before : " + Arrays.toString(arr));
        quickSort(arr, 0, arr.length - 1);
        System.out.println("After : " + Arrays.toString(arr));
    }
}
