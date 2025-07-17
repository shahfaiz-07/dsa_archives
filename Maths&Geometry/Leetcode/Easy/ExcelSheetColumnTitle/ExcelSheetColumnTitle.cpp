// https://leetcode.com/problems/excel-sheet-column-title/
#include <bits/stdc++.h>
using namespace std;

// RECURSIVE
string convertToTitle(int columnNumber)
{
    if (columnNumber == 0)
        return "";
    return convertToTitle((columnNumber - 1) / 26) + (char)((columnNumber - 1) % 26 + 65);
}

// ITERATIVE
public
String convertToTitle(int columnNumber)
{
    StringBuilder ans = new StringBuilder("");
    while (columnNumber > 0)
    {
        ans = ans.append((char)((columnNumber - 1) % 26 + 65));
        columnNumber = (columnNumber - 1) / 26;
    }
    return ans.reverse().toString();
}