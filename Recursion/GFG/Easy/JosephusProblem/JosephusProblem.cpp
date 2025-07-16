// https://www.geeksforgeeks.org/problems/josephus-problem/1
#include <bits/stdc++.h>
using namespace std;

int jp(int n, int k)
{
    if (n == 1)
        return 0;
    return (jp(n - 1, k) + k) % n;
}
int josephus(int n, int k)
{
    // code here
    return jp(n, k) + 1;
}