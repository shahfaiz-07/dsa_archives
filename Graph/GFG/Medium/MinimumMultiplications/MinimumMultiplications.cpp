// https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
#include<bits/stdc++.h>
using namespace std;
int minimumMultiplications(vector<int> &arr, int start, int end)
{
    // code here
    // applying dijkstra - what are the nodes?
    // 0 - 9999 as why have a modulo 10^5
    const int MOD = 1e5;
    vector<int> minSteps(MOD, INT_MAX);
    minSteps[start] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(0, start));

    while (!q.empty())
    {
        auto curr = q.front();
        int val = curr.second, steps = curr.first;
        if (val == end)
            return steps;
        q.pop();
        int newSteps = steps + 1;
        for (int &ele : arr)
        {
            int newVal = (val * ele) % MOD;

            if (minSteps[newVal] > newSteps)
            {
                minSteps[newVal] = newSteps;
                q.push(make_pair(newSteps, newVal));
            }
        }
    }

    return -1;
}
}
;

int main(void) {
    
    return 0;
}