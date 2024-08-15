#include<bits/stdc++.h>
using namespace std;
long long factorial(int n, long long product)
{
    if (n <= 1)
    {
        return product;
    }
    return factorial(n - 1, product * n); // using tail recursion
}
int main(void) {
    cout << factorial(20, 1) << endl;
    return 0;
}