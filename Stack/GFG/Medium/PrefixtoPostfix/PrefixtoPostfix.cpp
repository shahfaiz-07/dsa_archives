// https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1
#include<bits/stdc++.h>
using namespace std;
string preToPost(string pre_exp)
{
    stack<string> st;
    for (int i = pre_exp.length() - 1; i >= 0; i--)
    {
        char ch = pre_exp[i];
        if (isalnum(ch))
        {
            st.push(string(1, ch));
        }
        else
        {
            string left = st.top();
            st.pop();
            string right = st.top();
            st.pop();
            string exp = left + right + string(1, ch);
            st.push(exp);
        }
    }
    return st.top();
}