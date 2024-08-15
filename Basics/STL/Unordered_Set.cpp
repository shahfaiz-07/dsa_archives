#include<bits/stdc++.h>
using namespace std;

int main(void) {
    // STORES UNIQUE BUT NOT IN SORTED ORDER
    // lower_bound and upper_bound doesn't work rest all functions are same as set
    // as it doesn't store in sorted order it has better time complexity in much cases
    unordered_set<int> st;
    st.insert(2);
    st.insert(1);
    st.insert(3);
    st.insert(5);
    st.insert(4);

    st.erase(3);
    for(int i: st) {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}