// https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1
#include<bits/stdc++.h>
using namespace std;
vector<int> replaceWithRank(vector<int> &arr, int N)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    for (int i = 0; i < N; i++)
    {
        pq.push({arr[i], i});
    }

    int lastPop = 0, rank = 0;

    while (!pq.empty())
    {
        auto root = pq.top();
        pq.pop();

        int ele = root.first, ind = root.second;

        if (lastPop != ele)
        {
            rank++;
        }

        lastPop = ele;
        arr[ind] = rank;
    }

    return arr;
}
int main(void) {
    
    return 0;
}