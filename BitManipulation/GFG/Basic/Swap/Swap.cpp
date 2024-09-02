// https://www.geeksforgeeks.org/problems/swap-two-numbers3844/1
#include<bits/stdc++.h>
using namespace std;
pair<int, int> get(int a, int b)
{
    // complete the function here
    a = a ^ b;
    b = a ^ b; // ((a ^ b) ^ b)
    a = a ^ b; // ((a ^ b) ^ a)
    return make_pair(a, b);
}
int main(void) {
    pair<int, int> p = get(3, 4);
    cout << p.first << " " << p.second;
    return 0;
}