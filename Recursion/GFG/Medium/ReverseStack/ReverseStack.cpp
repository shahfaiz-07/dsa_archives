// https://www.geeksforgeeks.org/problems/sort-a-stack/
#include<bits/stdc++.h>
using namespace std;

void insertReversed(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
    }
    int y = st.top();
    st.pop();
    insertReversed(st, x);
    st.push(y);
}
void Reverse(stack<int> &st)
{
    if (!st.empty())
    {
        int x = st.top();
        st.pop();
        Reverse(st);
        stack<int> temp;
        while (!st.empty())
        {
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
    }
}
int main(void) {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    Reverse(st);
    while(!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}