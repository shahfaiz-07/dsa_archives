// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;
long long count(int n)
{
    if (n == 1)
        return 1;
    long long spaces = (n - 1) * 2 + 1;
    return (count(n - 1) * ((spaces * (spaces + 1)) % MOD) / 2) % MOD;
}
int countOrders(int n)
{
    return count(n) % MOD;
}