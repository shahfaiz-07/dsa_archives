#include<bits/stdc++.h>
using namespace std;
long long solve(vector<int> &bt)
{
    // code here
    sort(bt.begin(), bt.end());
    long long wait = 0, total = 0;
    for (int i = 1; i < bt.size(); i++)
    {
        wait = wait + bt[i - 1];
        total = total + wait;
    }
    return total / bt.size();
}
int main(void) {
    
    return 0;
}