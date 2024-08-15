//https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/
import java.util.ArrayList;

public class Union {
    static ArrayList<Integer> findUnion(int arr1[], int arr2[], int n, int m) {
        ArrayList<Integer> uni = new ArrayList<>();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (arr1[i] < arr2[j]) {
                if (uni.isEmpty() || uni.get(uni.size() - 1) != arr1[i]) {
                    uni.add(arr1[i]);
                }
                i++;
            } else if (arr1[i] == arr2[j]) {
                if (uni.isEmpty() || uni.get(uni.size() - 1) != arr1[i]) {
                    uni.add(arr1[i]);
                }
                i++;
                j++;
            } else {
                if (uni.isEmpty() || uni.get(uni.size() - 1) != arr2[j]) {
                    uni.add(arr2[j]);
                }
                j++;
            }
        }
        while (i < n) {
            if (uni.isEmpty() || uni.get(uni.size() - 1) != arr1[i]) {
                uni.add(arr1[i]);
            }
            i++;
        }
        while (j < m) {
            if (uni.isEmpty() || uni.get(uni.size() - 1) != arr2[j]) {
                uni.add(arr2[j]);
            }
            j++;
        }
        return uni;
    }
    public static void main(String[] args) {
        int arr1[] = {-5, -4, -1, 1, 7};
        int arr2[] = {-3, 0, 1, 8};
        ArrayList<Integer> uni = findUnion(arr1, arr2, 5, 4);
        System.out.println(uni);
    }
}
