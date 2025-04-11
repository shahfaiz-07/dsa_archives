// https://leetcode.com/problems/online-stock-span/
#include<bits/stdc++.h>
using namespace std;
class StockSpanner
{
private:
    stack<pair<int, int>> st;
    int c;

public:
    StockSpanner()
    {
        c = 0;
    }

    int next(int price)
    {
        while (!st.empty() && price >= st.top().first)
        {
            st.pop();
        }
        int ind = st.empty() ? -1 : st.top().second;
        st.push({price, c});
        c++;
        return c - ind - 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */