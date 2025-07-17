// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

public class CountAllValidPickupandDeliveryOptions {
    long MOD = (long)1e9 + 7;
    long count(int n) {
        if(n == 1) return 1;
        long spaces = (n - 1) * 2  + 1;
        return (count(n - 1) * ((spaces * (spaces + 1))%MOD)/2)%MOD; 
    }
    public int countOrders(int n) {
        return (int)(count(n)%MOD);
    }
}
