// https://leetcode.com/problems/koko-eating-bananas/
#include<bits/stdc++.h>
using namespace std;
int timeTaken(vector<int> &piles, double k)
{
    int h = 0;
    for (int &bananas : piles)
    {
        h += ceil(bananas / k);
    }
    return h;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int u = *(max_element(piles.begin(), piles.end()));
    int l = 1;
    int k = -1;
    while (l <= u)
    {
        int m = u - (u - l) / 2;
        int time = timeTaken(piles, m);
        if (time > h)
        {
            l = m + 1;
        }
        else
        {
            u = m - 1;
            k = m;
        }
    }
    return l;
}
int main(void) {
    
    return 0;
}