#include<bits/stdc++.h>
using namespace std;

int main(void) {
    // SET STORES EVERYTHING IN SORTED ORDER AND UNIQUE ELEMENTS
    // Operations like insert and erase take log(n) time
    set<int> st;
    st.insert(1);
    st.emplace(2);
    st.insert(1);
    st.insert(5);
    st.insert(4);
    st.emplace(3);
    // begin, end, rbegin, rend, size, empty, swap, erase

    for(int i: st) {
        cout << i << " ";
    }
    cout << endl;

    // #find(val) - Returns an iterator which points to 'val' else returns st.end()
    // #count(val) - Here since every element is unique it returns '1' if element is present else returns '0'

    // #lower_bound - Returns the first occurence (iterator) if it is present else the element just greater than it
    // #upper_bound - Returns the element just greater than last occurence of the given element even if it is present if the list
    return 0;
}