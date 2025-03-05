// https://leetcode.com/problems/happy-number
#include<bits/stdc++.h>
using namespace std;
bool isHappy(int n)
{
    while (n >= 10)
    {
        int sum = 0;
        while (n != 0)
        {
            int d = n % 10;
            sum = sum + d * d;
            n /= 10;
        }
        n = sum;
    }
    return n == 1 || n == 7;
}