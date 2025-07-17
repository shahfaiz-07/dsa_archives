// https://leetcode.com/problems/poor-pigs/
#include <bits/stdc++.h>
using namespace std;

int poorPigs(int buckets, int minutesToDie, int minutesToTest)
{
    int totalTrials = minutesToTest / minutesToDie;
    int T = totalTrials + 1;

    // T^(pigs) = buckets
    // pigs = log_T(buckets)

    return ceil(log10(buckets) / log10(T));
}