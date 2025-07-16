// https://leetcode.com/problems/new-21-game/
#include<bits/stdc++.h>
using namespace std;

double new21Game(int n, int k, int maxPts) {
        vector<double> P(n + 1, 0.0);
        P[0] = 1;
        double probSum = (k == 0) ? 0 : 1;
        for(int i=1; i<=n; i++) {
            P[i] = probSum/maxPts;
            if(i < k) {
                probSum += P[i];
            }
            if(i - maxPts >= 0 && i - maxPts < k)
                probSum -= P[i-maxPts];
        }
        double res = 0.0;
        for(int i=k; i<=n; i++) {
            res += P[i];
        }
        return res;
    }
