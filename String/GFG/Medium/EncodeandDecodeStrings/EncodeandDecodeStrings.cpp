// https://www.geeksforgeeks.org/problems/encode-and-decode-strings/1
#include<bits/stdc++.h>
using namespace std;
const string separator = "::";

string encode(vector<string> &s)
{
    // code here
    string codeWord = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        codeWord = codeWord + separator + s[i];
    }
    return codeWord;
}

vector<string> decode(string &s)
{
    // code here
    vector<string> decoded;
    string word = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (i < s.length() - 2 && s[i] == ':' && s[i + 1] == ':')
        {
            decoded.emplace_back(word);
            i += 1;
            word = "";
        }
        else
        {
            word = word + s[i];
        }
    }
    decoded.emplace_back(word);
    return decoded;
}