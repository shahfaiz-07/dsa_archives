// https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1
#include<bits/stdc++.h>
using namespace std;
string postToInfix(string &exp)
{
    // Write your code here
    stack<string> st;
    for (char &ch : exp)
    {
        if (isalnum(ch))
        {
            st.push(string(1, ch));
        }
        else
        {
            string right = st.top();
            st.pop();
            string left = st.top();
            st.pop();
            st.push("(" + left + ch + right + ")");
        }
    }
    return st.top();
}