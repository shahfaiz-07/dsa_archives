// https://leetcode.com/problems/string-to-integer-atoi/description/
#include<bits/stdc++.h>
using namespace std;

long parser(string s, int i, long num, bool isNeg)
{
    if (i == s.length() || s[i] < '0' || s[i] > '9')
    {
        return isNeg ? -num : num;
    }
    else if (isNeg && -(num * 10 + (s[i] - '0')) <= INT_MIN)
    {
        return INT_MIN;
    }
    else if (!isNeg && (num * 10 + (s[i] - '0')) >= INT_MAX)
    {
        return INT_MAX;
    }
    num = num * 10 + (s[i] - '0');
    return parser(s, i + 1, num, isNeg);
}

int myAtoi(string s)
{
    bool isNeg = false;
    int index = 0;
    if (s == "")
    {
        return 0;
    }
    while (index < s.length() && s[index] == ' ')
    {
        index++;
    }
    if (index < s.length() && s[index] == '-')
    {
        isNeg = true;
        index++;
    }
    else if (index < s.length() && s[index] == '+')
    {
        index++;
    }
    while (index < s.length() && s[index] == '0')
    {
        index++;
    }
    if (index < s.length() && s[index] >= '0' && s[index] <= '9')
    {
        return parser(s, index, 0, isNeg);
    }
    return 0;
}

int main(void) {
    cout << myAtoi("7657754764") << endl;
    return 0;
}