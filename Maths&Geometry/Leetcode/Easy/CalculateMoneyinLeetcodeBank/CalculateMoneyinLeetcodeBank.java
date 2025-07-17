// https://leetcode.com/problems/calculate-money-in-leetcode-bank/

public class CalculateMoneyinLeetcodeBank {
    public int totalMoney(int n) {
        int weeks = n/7, rem = n % 7;
        // ans = otherWeek(forms an AP where, a = 28, d = 7, n = weeks) 
        // + finalWeek(forms an AP where, a = weeks + 1, d = 1, n = rem)
        return (weeks * (2 * 28 + (weeks - 1) * 7))/2 + (rem * (2 * weeks + rem + 1))/2;
    }
}
