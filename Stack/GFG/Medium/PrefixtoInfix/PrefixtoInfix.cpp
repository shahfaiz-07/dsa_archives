// https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1
#include<bits/stdc++.h>
using namespace std;
string preToInfix(string &pre_exp)
{
    // Write your code here
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
            string first = st.top();
            st.pop();
            string second = st.top();
            st.pop();
            string exp = "(" + first + ch + second + ")";
            st.push(exp);
        }
    }
    return st.top();
}