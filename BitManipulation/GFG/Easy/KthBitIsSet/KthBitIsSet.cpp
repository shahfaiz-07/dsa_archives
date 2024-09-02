// https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1
#include<bits/stdc++.h>
using namespace std;
bool checkKthBit(int n, int k)
{
    // Your code here
    // It can be a one liner logic!! Think of it!!
    return ((n >> k) & 1);
}
int main(void) {
    cout<< checkKthBit(5, 2);
    return 0;
}