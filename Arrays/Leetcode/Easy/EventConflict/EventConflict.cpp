// https://leetcode.com/problems/determine-if-two-events-have-conflict/
#include<bits/stdc++.h>
using namespace std;
bool haveConflict(vector<string> &event1, vector<string> &event2)
{
    if (event1[0] > event2[0])
    {
        auto temp = event2;
        event2 = event1;
        event1 = temp;
    }
    return event1[1] >= event2[0];
}
int main(void) {
    
    return 0;
}