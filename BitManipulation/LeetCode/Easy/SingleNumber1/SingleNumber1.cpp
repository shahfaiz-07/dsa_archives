// https://leetcode.com/problems/single-number/
#include<bits/stdc++.h>
using namespace std;
int singleNumber(vector<int> &nums)
{
    int XOR = 0;
    for (int i : nums)
    {
        XOR = i ^ XOR;
    }
    return XOR;
}
int main(void) {
    
    return 0;
}