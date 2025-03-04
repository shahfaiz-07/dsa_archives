// https://leetcode.com/problems/valid-parentheses/
#include<bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
                return false;

            if (st.top() < ch - 2 || st.top() > ch)
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}