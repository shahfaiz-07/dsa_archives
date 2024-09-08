// http://www.geeksforgeeks.org/problems/introduction-to-dp/1

#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
long long int f(int n, vector<long long> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = (f(n - 1, dp) + f(n - 2, dp))%mod;
}
long long int topDown(int n)
{
    vector<long long int> dp(n + 1, -1);
    return f(n, dp);
}
long long int bottomUp(int n)
{
    if (n <= 1)
    {
        return n;
    }

    long long int a = 1, b = 0, curr = 0;
    for (int i = 2; i <= n; i++)
    {
        curr = (a + b) % mod;
        b = a;
        a = curr;
    }
    return curr;
}
int main(void)
{
    cout << "Enter a Number :";
    int n;
    cin >> n;
    cout << bottomUp(n) << "\n";
    cout << topDown(n);
    return 0;
}