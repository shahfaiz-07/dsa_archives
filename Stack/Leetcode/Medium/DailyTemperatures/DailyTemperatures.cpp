// https://leetcode.com/problems/daily-temperatures/description/
#include<bits/stdc++.h>
using namespace std;
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<pair<int, int>> st;
    for (int i = temperatures.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top().first <= temperatures[i])
        {
            st.pop();
        }
        int days = st.empty() ? 0 : st.top().second - i;
        st.push({temperatures[i], i});
        temperatures[i] = days;
    }

    return temperatures;
}