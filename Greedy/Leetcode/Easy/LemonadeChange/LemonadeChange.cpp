// https://leetcode.com/problems/lemonade-change/
#include<bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int> &bills)
{
    int five = 0, ten = 0;
    for (int i = 0; i < bills.size(); i++)
    {
        int diff = bills[i] - 5;
        if (diff == 0)
        {
            five++;
        }
        else if (diff == 5)
        {
            if (five)
            {
                five--;
                ten++;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (five && ten)
            {
                ten--;
                five--;
            }
            else if (five >= 3)
            {
                five -= 3;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
int main(void) {
    vector<int> bills = {5, 5, 10, 5, 10, 20, 5};
    cout << lemonadeChange(bills);
    return 0;
}