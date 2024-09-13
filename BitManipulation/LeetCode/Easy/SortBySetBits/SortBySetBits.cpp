// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
#include<bits/stdc++.h>
using namespace std;
vector<int> sortByBits(vector<int> &arr)
{
    auto lambda = [&](int &a, int &b)
    {
        int cA = __builtin_popcount(a); // Takes O(1) time
        int cB = __builtin_popcount(b);
        if (cA == cB)
            return a < b;
        return cA < cB;
    };
    sort(arr.begin(), arr.end(), lambda);
    return arr;
}
int main(void) {
    
    return 0;
}