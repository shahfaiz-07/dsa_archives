#include<bits/stdc++.h>
using namespace std;
long nthFibo(long n, map<long, long> &hash) {
    if(n == 0) {
        return 0;
    } else if(hash[n]) {
        return hash[n];
    }
    hash[n] = nthFibo(n - 1, hash) + nthFibo(n - 2, hash);
    return hash[n];
}
long fibonacci(long n) {
    map<long, long> hash;
    hash[0] = 0;
    hash[1] = 1;
    return nthFibo(n, hash);
}
int main(void) {
    cout << fibonacci(30);
    return 0;
}