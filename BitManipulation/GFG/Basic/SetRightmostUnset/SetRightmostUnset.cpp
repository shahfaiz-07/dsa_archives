// https://www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1
#include<bits/stdc++.h>
using namespace std;
int setBit(int n)
{
    // Write Your Code here
    return (n | n + 1);
}
int main(void) {
    cout << setBit(7);
    return 0;
}