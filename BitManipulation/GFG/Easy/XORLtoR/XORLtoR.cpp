// https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1
#include<bits/stdc++.h>
using namespace std;
// TC = O(1)
int calcXOR(int N)
{
    if (N % 4 == 1)
        return 1;
    if (N % 4 == 2)
        return N + 1;
    if (N % 4 == 3)
        return 0;
    return N;
}

int findXOR(int l, int r)
{
    // complete the function here
    if (l == 1)
        return calcXOR(r);
    return calcXOR(l - 1) ^ calcXOR(r);
}
int main(void) {
    
    return 0;
}