
import java.util.Arrays;

public class LambdaExpressions {
    public static void main(String[] args) {
        Integer[] arr = {1,2,3,4,5,6,7};
        Arrays.sort(arr, (a,b) -> {
            return b.compareTo(a);
        });
        System.out.println(Arrays.toString(arr));
    }
}
