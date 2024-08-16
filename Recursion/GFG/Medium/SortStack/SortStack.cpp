// https://www.geeksforgeeks.org/problems/sort-a-stack/1
#include<bits/stdc++.h>
using namespace std;
void sortedInsert(stack<int> &s, int x)
{
    if (s.empty() || s.top() <= x)
    {
        s.push(x);
        return;
    }
    int y = s.top();
    s.pop();
    sortedInsert(s, x);
    s.push(y);
}
void sortStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int x = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, x);
}
int main(void) {
    stack<int> st;
    st.push(1);
    st.push(4);
    st.push(0);
    st.push(9);
    st.push(6);
    sortStack(st);
    while(!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}