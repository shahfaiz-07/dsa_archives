// https://leetcode.com/problems/single-number-iii/
#include<bits/stdc++.h>
using namespace std;
vector<int> singleNumber(vector<int> &nums)
{
    long XOR = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        XOR = XOR ^ nums[i];
    }
    long separator = ((XOR & (XOR - 1)) ^ XOR);
    int b1 = 0;
    int b2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if ((separator & nums[i]) != 0)
        {
            b1 = b1 ^ nums[i];
        }
        else
        {
            b2 = b2 ^ nums[i];
        }
    }
    return {b1, b2};
}
int main(void) {
    
    return 0;
}