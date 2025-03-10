// https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1
#include<bits/stdc++.h>
using namespace std;
string infixToPostfix(string &s)
{
    // Your code here
    stack<char> st;
    string post = "";
    for (char &ch : s)
    {
        if (isalnum(ch))
        {
            post += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (st.top() != '(')
            {
                post += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && priority(ch) <= priority(st.top()))
            {
                post += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty())
    {
        post += st.top();
        st.pop();
    }
    return post;
}
int priority(char &ch)
{
    switch (ch)
    {
    case '^':
        return 2;
    case '*':
    case '/':
        return 1;
    case '+':
    case '-':
        return 0;
    }
    return -1;
}