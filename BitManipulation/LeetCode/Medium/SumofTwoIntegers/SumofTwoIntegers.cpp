// https://leetcode.com/problems/sum-of-two-integers/
#include<bits/stdc++.h>
using namespace std;
// MY APPROACH
int getSum(int a, int b)
{
    int carry = 0;
    int ans = 0, bit = 0;
    while (a && b && bit < 32)
    {
        ans = ans | (((a & 1) ^ (b & 1) ^ carry) << bit);
        carry = ((a & 1) & (b & 1)) | ((a & 1) & carry) | ((b & 1) & carry);
        bit++;
        a >>= 1;
        b >>= 1;
    }
    while (a && bit < 32)
    {
        ans = ans | (((a & 1) ^ carry) << bit);
        carry = ((a & 1) & carry);
        bit++;
        a >>= 1;
    }
    while (b && bit < 32)
    {
        ans = ans | (((b & 1) ^ carry) << bit);
        carry = ((b & 1) & carry);
        bit++;
        b >>= 1;
    }
    if (carry && bit < 32)
    {
        ans = ans | (carry << bit);
    }
    return ans;
}

// THE OPTIMAL
int getSum(int a, int b)
{
    while (b)
    {
        int carry = (a & b) << 1; // Carry: AND operation then left shift
        a = a ^ b;                // Sum without carry: XOR operation
        b = carry;                // Carry is added in next iteration
    }
    return a;
}