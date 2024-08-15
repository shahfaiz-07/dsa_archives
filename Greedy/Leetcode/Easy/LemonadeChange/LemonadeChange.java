// https://leetcode.com/problems/lemonade-change/
public class LemonadeChange {
    static boolean lemonadeChange(int[] bills) {
        int five = 0, ten = 0;
        for (int i = 0; i < bills.length; i++) {
            int diff = bills[i] - 5;
            if (diff == 0) {
                five++;
            } else if (diff == 5) {
                if (five > 0) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } else {
                if (five > 0 && ten > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
    public static void main(String[] args) {
        int bills[] = {5, 5, 10, 5, 10, 20, 5};
        System.out.println(lemonadeChange(bills));
    }
}
