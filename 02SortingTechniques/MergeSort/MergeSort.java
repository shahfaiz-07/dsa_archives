import java.util.Arrays;

public class MergeSort {
    static void merge(int arr[], int l, int m, int r) {
        int nL = m - l + 1, nR = r - m;
        int lArr[] = new int[nL], rArr[] = new int[nR];
        for (int i = l, j = 0; i <= m; i++, j++) {
            lArr[j] = arr[i];
        }
        for (int i = m + 1, j = 0; i <= r; i++, j++) {
            rArr[j] = arr[i];
        }
        int lp = 0, rp = 0, k = l;
        while (lp < nL && rp < nR) {
            if (lArr[lp] <= rArr[rp]) {
                arr[k++] = lArr[lp++];
            } else {
                arr[k++] = rArr[rp++];
            }
        }
        while (lp < nL) {
            arr[k++] = lArr[lp++];
        }
        while (rp < nR) {
            arr[k++] = rArr[rp++];
        }
    }

    static void mergeSort(int arr[], int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2; // prevents integer overflow
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    public static void main(String[] args) {
        int arr[] = { 1, 4, 5, 2, 5, 6, 5, 0, 2, 1 };
        System.out.println("Before : " + Arrays.toString(arr));
        mergeSort(arr, 0, arr.length - 1);
        System.out.println("After : " + Arrays.toString(arr));
    }
}
