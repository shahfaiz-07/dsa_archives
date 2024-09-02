// https://leetcode.com/problems/power-of-two/description/
#include<bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n)
{
    // remove the last set bit and check is the number is 0 or not
    return (n > 0 && !(n & n - 1));
}
int main(void) {
    cout << isPowerOfTwo(45) << "\n" << isPowerOfTwo(32);
    return 0;
}