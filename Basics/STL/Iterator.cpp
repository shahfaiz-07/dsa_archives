#include<iostream>
#include<iterator>
#include<vector>
using namespace std;

int main() {
    vector<int> ar = {1, 2, 3, 4, 5};

    //-----------------------------------------------------------------------------------
    // DEFINING
    //-----------------------------------------------------------------------------------
    vector<int>::iterator ptr;

    //-----------------------------------------------------------------------------------
    // FUNCTIONS
    //-----------------------------------------------------------------------------------

    // # begin() :- This function is used to return the beginning position of the container.
    // # end() :- This function is used to return the after end position of the container.
    for (ptr = ar.begin(); ptr < ar.end(); ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;

    // #back() - Last item of the vector
    cout << "Back :" << ar.back() << endl;

    // # advance() :- This function is used to increment the iterator position till the 
    // specified number mentioned in its arguments.

    ptr = ar.begin();
    advance(ptr, 3);
    cout << *ptr << endl;

    // # next() :- This function returns the new iterator that the iterator would point
    //                  after advancing the positions mentioned in its arguments.
    // # prev() :- This function returns the new iterator that the iterator would point 
    //                  after decrementing the positions mentioned in its arguments.

    ptr = ar.begin();
    vector<int>::iterator ftr = ar.end();

    auto it1 = next(ptr, 3);
    auto it2 = prev(ftr, 3);

    cout << *it1 << " " << *it2 << endl;

    // 
    return 0;
}