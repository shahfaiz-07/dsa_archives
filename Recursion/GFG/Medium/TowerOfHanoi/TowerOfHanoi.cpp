// https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/
#include<bits/stdc++.h>
using namespace std;
long long toh(int n, int from, int to, int aux)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
        return 1;
    }
    long long x = toh(n - 1, from, aux, to);
    x += 1;
    cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
    x += toh(n - 1, aux, to, from);
    return x;
}
int main(void) {
    cout << toh(3, 1, 2, 3);
    return 0;
}