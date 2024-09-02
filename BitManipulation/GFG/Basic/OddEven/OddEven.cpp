// https://www.geeksforgeeks.org/problems/odd-or-even3618/1
#include<bits/stdc++.h>
using namespace std;
string oddEven(int n)
{
    // code here
    return (n & 1) ? "odd" : "even";
}
int main(void) {
    cout << oddEven(5);
    return 0;
}