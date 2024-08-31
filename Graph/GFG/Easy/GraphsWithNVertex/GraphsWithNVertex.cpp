// https://www.geeksforgeeks.org/problems/graph-and-vertices/1
#include<bits/stdc++.h>
using namespace std;
long long count(int n)
{
    long long ans = pow(2, (n * (n - 1) / 2));
    return ans;
}
int main(void) {
    cout << count(5);
    return 0;
}