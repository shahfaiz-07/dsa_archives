// https://www.geeksforgeeks.org/problems/second-largest3735/
public class SecondLargestElement {
    static int print2largest(int arr[]) {
        int m = arr[0];
        for(int i=0; i<arr.length; i++) {
            if(arr[i] > m) {
                m = arr[i];
            }
        }
        int sm = arr[0];
        if(m == arr[0]) {
            sm = arr.length > 1 ? arr[1] : arr[0];
        }
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] > sm && arr[i] < m) {
                sm = arr[i];
            }
        }
        return sm != m ? sm : -1;
    }
    public static void main(String[] args) {
        int arr[] = {12, 35, 1, 10, 34, 1};
        System.out.println(print2largest(arr));
    }
}
