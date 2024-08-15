#include<bits/stdc++.h>
using namespace std;

bool isValid(string str, int index) {
    if(index >= str.length()/2) {
        return true;
    }
    if(str[index] != str[str.length() - index - 1]) {
        return false;
    }
    return isValid(str, index + 1);
}
int main(void) {
    cout << isValid("llol", 0);
    return 0;
}