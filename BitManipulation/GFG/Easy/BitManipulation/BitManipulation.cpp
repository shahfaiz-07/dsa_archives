// https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1
#include<bits/stdc++.h>
using namespace std;
void bitManipulation(int num, int i)
{
    cout << ((num >> (i - 1)) & 1) << " ";
    cout << (num | (1 << (i - 1))) << " ";
    cout << (num & ~(1 << (i - 1)));
}
int main(void) {
    bitManipulation(5, 2);
    return 0;
}