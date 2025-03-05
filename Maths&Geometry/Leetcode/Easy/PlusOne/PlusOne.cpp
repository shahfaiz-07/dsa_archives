// https://leetcode.com/problems/plus-one/
#include<bits/stdc++.h>
using namespace std;
vector<int> plusOne(vector<int> &digits)
{
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0 && carry; i--)
    {
        int val = digits[i] + carry;
        digits[i] = val % 10;
        carry = val / 10;
    }
    if (carry)
    {
        digits.emplace_back(0);
        digits[0] = 1;
    }
    return digits;
}